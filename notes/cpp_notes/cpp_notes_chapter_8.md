# Structures, Unions and Enumerations 


## intro
* struct: is a sequence of elements (called members) of arbitrary types
* union: is a struct that holds the value of just one of its elements at any one time.
* enum: is a type with a set of named constants 
* enum class: is an enum where the enumerators are within the scope of the enumbertion and no implicit conversions to other types provided

## struct
* layout, alignment: to save space, you can put the var with largest size on the top, otherwise, you need to waste space by alignment. only do this when really needs to.
```
struct A {
    int x ;
    char y;
    char z;
};

struct B {
    char x;
    int y;
    char z;
};
int main() {
    
    cout << sizeof(A) << endl; // 8
    cout << sizeof(B) << endl; // 12
}
```
* You cannot have recursive as `struct A { A x};` since the compiler cannot determine the size. However you can do something as below
  ```
    struct List ;   // you need to delcare List with not definition, thus Link cannot use it 

    struct Link {
        Link* x;
        List* y;
    };

    struct List {
        Link* head;
    };
  ```
* you can overload by using the `struct`, however it is not recommended
  ```
    struct X {
      int a ; 
    };

    int X(int age){
        cout << age << endl;
    };

    int main() {
        struct X x {1};
        X(10);
   } 
  ```
* structure and class: structure is simple a class where all members are public. thus you can have constructor as the class does. 
  ```
    struct X {
      int a, b;
    
      int sum(){
          return a + b ;
      }
    };


    int main() {
      X x {1,2};
      cout << x.sum() << endl;
    }
  ```
