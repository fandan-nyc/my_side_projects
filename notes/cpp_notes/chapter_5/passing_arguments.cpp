#include <thread>
#include <iostream>
#include <vector>

using namespace std;

void f(const vector<int>& vector, int* res){
   int sum = 0; 
   for(const auto& i: vector){
      sum += i;
   }
   *res = sum;
}

class F{
   public:
   F(const vector<int>& vv, int* resv): v{vv}, res{resv} {
      
   }
   
   void operator()(){
      int sum = 0; 
      for(const auto& i: v){
         sum += i;
      }
      *res = sum;
   }
   
   private:
      const vector<int>& v;
      int* res;
};

int main(){
   const vector<int> data = {1,2,3,4};
   int res = 0;
   int* res2 = new int;
   thread t1 {f, cref(data), &res};
   thread t2 {F(cref(data), res2)};

   t1.join();
   t2.join();
   
   cout << res << endl;
   cout << *res2 << endl;
}
