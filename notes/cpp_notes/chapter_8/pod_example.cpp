#include <iostream>
#include <type_traits>
#include <cstring>

using namespace std;

struct Point {
    int x, y;
};

struct complicated {
    int x,y;
    complicated(int a): x{a} {};
};

template<typename T>
void copy(T* to, T* from, int count){
    if(is_pod<T>::value){
        cout << "pod copy" << endl;
        memcpy(to, from, count * sizeof(T));
    }else{
        cout << "non pod copy" << endl;
        for(int i = 0; i != count; i++){
            to[i]=from[i];
        }
    }
};



int main() {
    Point from[] {{1,2},{3,4}};
    Point to[2];
    copy<Point>(to, from, 2); // pod copy
    cout << to[1].x << endl; // 3
    
    complicated from2[] {complicated{1}, complicated{2}};
    complicated to2[] {complicated{3}, complicated{4}};
    copy<complicated>(to2, from2, 2); // non pod copy
    cout << to2[1].x << endl; // 2
}
