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
  * const 
  * constexpr
