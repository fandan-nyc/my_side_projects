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
    * static storage
    * stack: 
    * heap: legacy from C. variables created through malloc and delete through free.
    * free storre: all local variables in C++ goes here
