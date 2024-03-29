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
* struct and std::array
```
struct Point {
    int x, y;
};

int main() {
    using Array = std::array<Point, 3>;
    Array x {{{1,2},{3,4}, {5,6}}};
    cout << x[1].x; // 3
}
```
Note that, for std::array, you need to give type and length. you cannot deduct from the input
```
int main() {
    int t[] =  {1,2,3};
    std::array<int> z {1,2,3}; // does not work
}
```
* POD (plain old data)
  * pod is an object that can be manipulated as just data without worrying about complications of class layouts or user-defined semantics. 
    ```
      struct S2 {int a; S2(int aa} : a(aa){}}; // not a pod, you do not have default constructor 
      struct S3 {int a; S3(int aa} : a(aa){}; S3(){}}; // not a pod, user defined default
      struct S4 {int a; S4(int aa} : a(aa){}; S4()=default}; // POD 
    ```
  * [example](https://github.com/fandan-nyc/my_side_projects/blob/master/notes/cpp_notes/chapter_8/pod_example.cpp) is here

## Unions
* Union is a struct. 
* Union is a struct in which all members are allocated into the same address, so that the union occupies only as much as space as its largest member. 
* natually, a union can only hold a value for only one member at a time. 
* In this [example](https://github.com/fandan-nyc/my_side_projects/blob/master/notes/cpp_notes/chapter_8/union_old.cpp), we can simplify by union.
* Here is the [union exmaple](https://github.com/fandan-nyc/my_side_projects/blob/master/notes/cpp_notes/chapter_8/union_new.cpp)
## Enum
