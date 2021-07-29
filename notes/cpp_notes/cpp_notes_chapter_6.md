# Types and Declarations 

This chapter includes 
* ISO C++ standard 
* Types
* Declarations
* Objects and Values
* Type Alias

## Types
* A C++ implementation could be hosted or freestanding.
  * hosted implementatino -> include ALL standard-library facilities as described in the standard
  * a freestanding implementation -> fewer standard-library facilities -> meant for code running with only the most minimal operating system support
* check the following type hierarchy:
  ```
   bool -|
   int  -| ---> integral types  -------|
   char -|                             |
                                       | -> arithmetic type -->|
   floating points          ---------- |                       | -> built-in types
   pointer, reference                      --------------------|
   
   enum + class -> user defined types
  ```
### bool
```
   bool a = 7; // true
   bool b {7} ; // error: narrowing
   int a1 = a; // 1
   int b1 {true}; // 1
   
   // you can also do arithmetic operation
   bool a = true;
   bool b= true;
   bool x = a+b ; // true
   bool y = a-b ; // 1-1 = 0 and 0 is false
   bool z = a || b ; // true 
   
   // pointer -> bool, nullptr -> fales, valid pointer = true;
```

### character type
* types
  * char: default, 8 bits
  * signed_char: guaranteed to be signed
  * unsigned_char: guaranteeed to be unsigned
  * wchar_t: the size of wchar_t is implementaion defined and large enough to hold the largest character set supported by the implementation's locale. 
  * char16_t: hold 16 bit char
  * char32_t: hold 32 bit char
* conversion
  * you can do `int{c}` where c is a char. then the question is that is the char signed or unsigned. 
    * the 256 values represented by 8-bit byte can be 0-255 or -127-127. Not -128 since we eliminate the -128 to leave it open for one's supplement machine. 
    * the choice of signed / unsigned is implementation defiend. 
    * example of printing out 1-10 char.
    ```
      #include <iostream>

      using namespace std;

      int main(){
        for(int i = 0; i < 10; i++){
          cout << static_cast<char>('0' + i) << endl;
        }
      }
    ``` 
    you cannot convert the char pointer for different types. but the char value can be assigned cross (with risky of truncation).
    but it is implementation defined. 
    ```
      #include <iostream> 

      int main(){
        signed char sc = 'b';
        char * cp = &sc; // cannot convert
      }
    ```
    
### int type
* decimal, octal and hexadecimal.
* hexadecimal -> with 0x prefix
* octal -> with 0 prefix 
* 0 is octal. there is no decimal 0. 

### floating point
* float, double, long double 
* float is single precision, double is double precision, and long double is extended precision. 
* the definition of single precision, double precision and extended precision is implementation-defined
* default, a floating number is double. if you need a float, use 12.3F, if you do 12.3L it is a long double

## alignment
* [this](https://lecoding.com/post/2016/about-cpp-alignment/) is a good article in chinese, which explained the idea very well
 ```
 #include <iostream> 

 using namespace std;

 struct ClassName {
   short num;
   char x;
 };

 int main(){
   cout << "char: " <<   alignof(char) << endl; // 1
   cout << "int: " <<   alignof(int) << endl; // 4
   cout << "double: " <<   alignof(double) << endl; // 8
   cout << "string: " << alignof(string) << endl; // 8
   cout << "char*: " << alignof(char*) << endl; // 8
   cout << "ClassName: " << alignof(ClassName) << endl; // 2
   cout << "ClassName size: " << sizeof(ClassName) << endl; // 4
 }
 ```
### Scope
you can use ::x to refer to global var. 
```
 #include <iostream>

using namespace std;

int x = 1;
int main(){
  cout << x << endl; // 1
  {
    int x = 2;
    cout << x << endl; // 2
    cout << ::x << endl; // 1
    ::x = 10; 
  }
  cout << x << endl; // 10
  cout << ::x << endl; //10
}
```
### initialization
always use {}, to avoid truncating and narrowing. the following 4 all works, but {} is the only one which can be used globally.
```
int x {12};
int x = {12};
int x 12;
int x(12); 
```
combining auto with {} is confusing 
```
auto x {12}; // initializer_list<int>
auto x = 12; // int
```
```
vector<int> v1 {99}; // vector of 1 ele, value = 99
vector<int> v2 (99); // vector of 99 elements, value = 0 for each
```
missing initializer
* a good use case without initializer is a large input buffer
  ```
    constexpr int max = 1024 * 1024;
    char buff[max]; // without int 
    char buff[max]{}; // with initialization, every char is 0 in this case.
  ```
* no init example 
  ```
     int x ;  // no init value
     char buf[1024]; // buf[i] does not have a well defined value
     
     int* p {new int}; // *p does not have a well defined value
     char* q{new char[1024]}; // q[i] does not have a well defined value
     
     string s ; // init == ""
     vector<char> v ; // init with empty vector 
     
     string* s {new string} ; // *s == ""
  ```
* init example
  ```
    int x {}; // x -> 0
    char buf[1204] {} ;// init, buf[i] == 0
    
    int* p {new int{10}};
    char* q{new char[1024]{}}; // this and above, {} is used to give init value
  ```
### declarator
```
int * x, y; // it is int* x and int y; the int is base type, the * is declarator operator
int x[10], *y;
```
### the auto type specifier
```
auto v1 = 1234 ;   // int 
auto v1 {1234}; // list of int
```
always use = with auto, whenever we do not mean list to ensure the correctness

### decltype
```
#include <iostream>

using namespace std;

template<typename A, typename B>
decltype(A{} + B{}) sum(A a, B b){
    return (a+b);
}

int main(){
    auto f = [](int a, int b){
        return a+b;
    };
    decltype(f) g = f ;
    cout << g(1,3) << endl;
    cout << typeid(sum(1, 23.4)).name() << endl; // d
    cout << typeid(sum("acc", 'b')).name() << endl;

    cout << sum('a' , 'b') << endl;

}
```
Note that, the f is a lambda func, with no type defined and unique.
also, the template for decltype(A{} + B{})

### Left Value and Right Value
* has identity: the program has the name of, pointer to, or reference to the object, so that it is possible to determine if two objects are the same, whether the value of the object has changed etc. 
* is movable: the object can be moved from (we can move its value to another location, and leave the object in a valid but unspecified statem, rather than copy)
* we use i = has identify, m = is movable
```
   lvalue (i & !m)              xvalue (i & m)          prvalue (!i & m)
        |                          |  |                         |
        ---------------------------   ---------------------------
                       |                           |
                    glvalue (l)                   rvalue (m)
```
