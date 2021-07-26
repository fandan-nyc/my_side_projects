#include <iostream> 
#include <memory>

using namespace std;

int main() {
  int* x = new int;
  *x = 1;
  cout << *x << endl; // 1
  unique_ptr<int> sp {move(x)};
  *x = 2;
  cout << *sp.get() << endl; // 2
}
