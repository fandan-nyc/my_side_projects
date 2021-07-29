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
