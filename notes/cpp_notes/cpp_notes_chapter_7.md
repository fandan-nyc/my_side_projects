# Pointers, Arrays and References

## Pointers
the * for *p here is a dereference operator.
```
char x = 'a';
char* p = &x;
char t  = *p;
```
here are some examples of using pointer
```
int* pi ; // pointer to int
char** ps ; // pointer to a pointer to char
int* x[15]; // an array of 15 pointers pointing to int
int (*fp)(char*); // pointer to a func, whose input is char* and return int

int * fp(char*) ; // a func, whose input is char* an dthe return is int*

```
* void*
  * mainly used for very low level programming, such as `void* my_alloc(size_t n)`.
  * for high level programming, we generally do not use it
  * you can cast as `static_cast<int*>(pv)`
* nullptr
  * used to have `int* x = 0;`
* arrays
  * unless you just need is a simple fixed-length sequence of objects of a given type in mem, you should choose vector over array
  * mem alloction for different usage: static storage, heap, free store
    * static storage // life time is the entire execution of the program
    * stack: local variable
    * heap: legacy from C. malloc and free
    * free store: new and delete
  ```
     int a1[10]; // static storage
     
     void f(){
       int a2[20];  // on the stack 
       int* p = new int[40]; // free store
       int* t = malloc(5); // heap -> C style
     }
  ```
  read this [article](https://www.moderncplusplus.com/free-store-vs-heap/)
* array initializer: array cannot be copied and there is array assignment
  ```
    #include <iostream>

    using namespace std;

    int main(){
      int x[5] = {1,2,3,4};
      int y[5] = {1,10};
      y = x; // error: invalid array assignment
      int t[5] = x ; //  error: array must be initialized with a brace-enclosed initializer
    } 
  ```
  
