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
