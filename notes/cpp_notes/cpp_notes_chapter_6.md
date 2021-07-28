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
