# the C++ programming language (4th)
Author: Bjarne Stroustrup

## Chapter 2: a tour of C++
* what is declaration:
  * a statement that introduces a name into the program. it specifies a type for the named entity
    * what is variabled  => a named object
    * what is object => some mem that holds a value of some type
    * what is value => a set of bits interpreted according to a type
    * what is type => defines a set of possible values and operations

* using = vs {}
  ```
  double x = 1.2; 
  double x {1.2};
  double x = {1.2};  // all 3 works 
  
  // always use {} to avoid implicit conversion 
  int x = 1.2 ; // will work 
  int x {1.2} // error: floating point to int conversion
  ```
* const
  
  there are two types of immunity in c++
  * *const* : ompiler will enforce the promise made by const (but evaluated at riun time)
  * *constexpr*: meaning roughly "to be evaluated at compile time". this is used primarily to specify constants, to allow placement of data in read-only mem and for perf. 
  ```
    const int x = 1;
    int var = 2;
    constexpr doubler max = 1.4 * square(x) ; // works
    constexpr double max2 = 1.4 * square(var); // does not work, since var is not const at compile
    const double max3 = 1.4 * square(var); // works, evaluated at runtime
  ```
  ```
   double sum(const vector<double> &); // func
   vector<double> data {1,2,3.8};
   const double s1 = sum(data) ; // ok
   constexpr double s2 = sum(data); // not okay, sum is not const
  ```
  ***for a func to be used for constexpr, you need to define the func as constexpr.***
  
  meanwhile, we allow constexpr func to be used for non const var, and the result of the func is mutable.
  ```
  #include <iostream>

  constexpr int sum( int a,  int b) {
    return a + b;
  }

  int main(){
    const int a = 1;
    const int b = 2;
    constexpr auto t = sum(a, b);
    auto tt = sum(a, b); // work as well
    int c = 3;
    int d = 4;
    constexpr res = sum(c, d) // will not work, c and d has to be const
  }
  // note that, even in const expr func, the var a and b are not const int, but the input has to be const in
  // if you pass int a
  ```


