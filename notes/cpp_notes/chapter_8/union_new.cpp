#include <iostream>

using namespace std;

enum Type {str, num};

union Value {
    char* x ;
    int y;
    
    Value(int a): y{a}{};
    Value(char* t): x{t}{};

};

struct Data {
    Type type;
    Value v;
};

void f(Data* d){
    if(d ->type == str){
        cout << d->v.x << endl;
    }else{
        cout << d->v.y << endl;
    }
};

int main(){
  //  Value v {123};
  char t[] {'a','b', '\0'};
    Data e1 {str, Value{t}}; // warning, you cannot convert string to char*
    Data e2 {num, Value{123}};
    f(&e1);
    f(&e2);
}
