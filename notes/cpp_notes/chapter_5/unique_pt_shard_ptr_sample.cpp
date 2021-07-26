#include <iostream> 
#include <memory>

using namespace std;

void addOne(shared_ptr<int> x){
  *x.get() += 1;
}

void addTwo(shared_ptr<int> y){
  *y.get() += 2;
}

void addThree(unique_ptr<int> z){
  *z.get() += 3;
}

void func1(){
  int* x = new int;
  *x = 10;
  shared_ptr<int> data {x};
  addOne(data);
  addTwo(data);
  cout << *x << endl;
  data.reset();
  cout << *x << endl;
}

void func2(){
  int* x = new int;
  *x = 10;
  unique_ptr<int> data {x};
  addThree(data);
  addThree(move(data));
  //cout << *(data.get()) << endl; --> fail, since data had been moved
  // addThree(data) will fail as well, use of deleted function (cannot copy, just move)
}

int main() {
  func1();
  cout << "----" << endl;
  func2();
}
