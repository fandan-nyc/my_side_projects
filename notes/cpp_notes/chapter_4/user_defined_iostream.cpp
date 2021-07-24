#include <iostream>
#include <string> 

using namespace std;

struct Entry{
    string name;
    int number;
};

ostream& operator<<(ostream& os, const Entry& e){
    return os << "{\"name\":" << e.name << ", " << "\"number\":" << e.number << "}";
}

int main(){
    Entry e  {"Dan", 1};
    cout << e;
}
