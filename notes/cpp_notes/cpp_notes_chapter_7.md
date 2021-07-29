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
