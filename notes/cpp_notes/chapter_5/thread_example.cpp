#include <iostream>
#include <thread>

using namespace std;

void f(){
  cout << "hello f f f" ;
}

struct F {
  void operator()(){
    cout << "world F F";
  }
};

int main() {
  thread t1 {f};
  thread t2 {F()};
  
  t1.join();
  t2.join();
}
