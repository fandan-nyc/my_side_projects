#include <iostream> 
#include <algorithm> 
#include <vector>
#include <string>
#include <typeinfo>

using namespace std;
bool findFunc1(string& data, char x){
  string::iterator res;
  res = find(data.begin(), data.end(), x);
  return res != data.end();
}

template<typename Container, typename Value>
bool findFunc2( Container& c,  Value v){
  typename Container::iterator res = find(c.begin(), c.end(), v);
  // here string::iterator is replaced by type Container::iterator
  return res != c.end();
}

template<typename T>
using Iterator = typename T::iterator;

template<typename Container, typename Value>
bool findFunc3(Container& c, Value v) {
  Iterator<Container> i = find(c.begin(), c.end(), v);
  return i != c.end();
};

int main() {
  string data = "xabbcc";
  bool res = findFunc2<string, char>(data, 't');
  cout << res << endl;
  res = findFunc2<string, char>(data, 'x');
  cout << res << endl;
  res = findFunc3<string, char>(data, 'x');
  cout << res << endl;
}
