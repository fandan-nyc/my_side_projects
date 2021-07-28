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
