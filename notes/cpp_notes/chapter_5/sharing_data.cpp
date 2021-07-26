#include <iostream>
#include <mutex> 
#include <thread>

using namespace std;

class Inventory {
   public:

      Inventory(int number): totalnum{number}{};
      mutex m; 
      int totalnum;
};

void printInventory(const string name, const Inventory& inv){
   cout << "inventory: "  << name << ", "<< inv.totalnum << endl;
}

void transfer(Inventory& from, Inventory& to, int num){
   unique_lock<mutex> lock1 {from.m, defer_lock};
   unique_lock<mutex> lock2 {to.m, defer_lock};
   lock(lock1, lock2);
   from.totalnum -= num;
   to.totalnum += num;
   printInventory("from", from);
   printInventory("to", to);
}



int main(){
   Inventory from {10};
   Inventory to {5};
   
   thread t1 {transfer, ref(from), ref(to), 2};
   thread t2 {transfer, ref(to), ref(from), 7};
   t1.join();
   t2.join();
}
