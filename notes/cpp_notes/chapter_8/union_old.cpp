#include <iostream>

using namespace std;

enum Type {str, num};

struct Entry {
    string name;
    Type t;
    string s; 
    int i;
};

void f(Entry* p){
    if(p->t == str){
        cout << p->s << endl;
    }else {
        cout << p->i << endl;
    }
};

int main(){
    Entry e1 {"e1", str, "hi",0 };
    Entry e2 {"e1", num, "", 123 };
    f(&e1);
    f(&e2);
}
