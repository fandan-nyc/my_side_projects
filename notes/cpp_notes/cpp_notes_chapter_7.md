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
* string literals
  * you can have a long string broken into two lines as below
    ```
      int main(){
        char x[] =  "aa"
          "bb";
       string y = "tt"
         "zz";
       cout << y << endl;
      }
    ```
  * raw string literal:  R"( and )" is the delimiter, anything in between is considered as part of the string
    ```
      string x  = R"("\t\t\t")";
      cout << x << endl; // "\t\t\t"
          string y = R"(a
    b
      c
    )";
    ``` 
    Note that, y in this case, contains \n and space.
  * passing array
    ```
      void printArray(int[][] data, int x, int y);
      // test.cpp:6:25: error: declaration of ‘m’ as multidimensional array must have bounds for all dimensions except the first
    ```
    ```
      #include <iostream>

      using namespace std;

      void printArray(int m[][4], int x, int y){
          for(int i = 0; i< x; i++){
              for(int j = 0; j < y; j++ ){
                  cout << m[i][j] << '\t';
              }
          }
          cout << "----" << endl;
      }

      void printArray2(int* m, int x, int y){
          for(int i = 0; i < x; i++){
             for (int j  = 0; j < y; j++){
                  cout << m[i*y + j] << '\t';
              }
          }
          cout << "-----" << endl;
      }
      int main(){
          int m[3][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
          printArray(m, 3, 4);
          printArray2(&m[0][0], 3, 4); // the first element of the array (even it is multi-dimensional)
          printArray2(m, 3, 4); // error: cannot convert ‘int (*)[4]’ to ‘int*’ for argument ‘1’ to ‘void printArray2(int*, int, int)’
      }
    ```
### Pointers and const
* const pointer vs the pointer to const
* Note that: const modifies the data type. so const int and int are two different data types. 
  ```
    #include <iostream> 

    using namespace std;
    int main(){
        char s[] = "abcd";
        char ss[] = "efgh";
        const char * t1 = s; 
        // t[2] = 5; you cannot assign to a value -> const value 
    
        char* const t2 = s ; // const pointer, pointer to values 
        t2[1] = 'z';
        cout << s << endl; // change value 
        // t2 = s; //this will fail.
    
        const char* const t3 = s; // change of pointer or change of value will fail   
    }
  ```
  ```
    #include <iostream> 

    using namespace std;
    int main(){
    int i = 0;
    const int j = 1; 
    cout << "j is const ? "  << std::is_const<decltype(j)>::value << endl; // 1
    cout << "i is const ? "  << std::is_const<decltype(i)>::value << endl; // 0
    cout << typeid(i).name() << endl; // show as i
    cout << typeid(j).name() << endl; // show as i
   }
  ```
* and you cannote `delete` the object not created by `new`. 
  ```
    #include <iostream> 

    using namespace std;
    int main(){
       int i = 0;
       int *j = &i;
       int* k {new int{12}};
       delete k; // ok, you can delete something created by new
       delete j; // free(): invalid pointer, bash: line 12: 22038 Aborted $file.o
    }
  ```
### References 
* there are lvalue references, const reference and rvalue reference.
  * lvalue reference: to refer to objects whose value we want to change
  * const reference: to refer to objects whose value we donot want to change 
    * Note tha,t const reference is considered as lvalue reference as well.  
  * rvalue reference: to refer to objects whose value we do not preserve afer we have used it (temporary)

#### Lvalue reference
* reference to the lvalue. you need to initialize the reference. you can have nullptr, but there is no null reference.
  ```
    using namespace std;
    int main(){
      int var = 1;
      int& t {var};
      t = 2;
      cout << var << endl; // var is 2
     // int& tttt; // error: ‘tttt’ declared as reference but not initialized
      extern int& tt; // ok, you can init somewhere 
    }
  ```
* const reference
  ```
    #include <iostream> 

    using namespace std;
    int main(){
        // ******* cannot bind non-const lvalue reference of type int& to an rvalue of tyoe int 
        // int& x1 {1};  // error 
        const int& x2 {1};
        cout << x2 << endl;
        // x = 12; // assignment of read-only reference 'x'
    }

  ```
#### Rvalue reference 
* reference reading is [here](http://thbecker.net/articles/rvalue_references/section_01.html)
* rvalue reference can bind to a rvalue, not a lvalue
  ```
    int main() {
      string yy = "abc";
      // string&& x {yy}; // error
      string&& x {"123"};
      cout << &x << endl;
      x = "456";
      cout << x << endl;
      cout << &x << endl;
  }
  ```
* we do not use const rvalue reference, since most of the benefits from using rvalue reference involve writing to the object to which it refers.
* it aims to solve two problems: 
  *  perfect forwarding
  *  moving semantics
* `std::move(x)` just a cast to be T&&
  ```
   #include <iostream>
   using namespace std;

   void test(int& x){
      // can only handle lvalue
      cout << x << endl;
   }

   void test(int&& t){
      // rvalue
      cout << "rvalue" << t << endl;
   }

   int main() {
    int x =  1;
    test(x); // lvalue
    int& y = x; 
    test(y); // lvalue
    test(1); // rvalue
  }
```

#### Reference to Reference 
* reference ot reference can only happen as the result of an alias / a template type argument
```
  using rr_i = int&&;
  using lr_i = int&;
  using rr_rr_i = rr_i&&; // is int&&
  using lr_rr_i = rr_i& ; // int&& & -> int&
  using rr_lr_i = lr_i&&; // int& && -> int&
  using lr_lr_i = lr_i&; // int& & -> int&
```
  this is called reference collapse. lvalue always win =D 

#### pointers and references 
* if you need to change which object you are referring to, use pointer and you can move pointer by += -= etc
* if you want ot be sure that a name always refers to the same object. use a reference. 
* it is IMPOSSIBLE to redefine an operator for a pair of built-in types. such as pointer. so if you need to use a user-defined (overloaded) operator, on something, you need to use a reference. 

