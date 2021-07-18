#include <iostream>

using namespace std;
class Vector {
public:
    Vector(int s) :ele {new double[s]}, size {s} {
    };
    
    double& operator[](int pos) {
        return ele[pos];
    }
    
    int getSize() const {
       // this -> size = 1; will not work
        return this -> size;
    }
    
    const int getSize2() {
        this -> size = 2;
        return this -> size;
    }
private:
    double* ele;
    int size; 
    
};

int main(){
    Vector v {9};
    cout << v.getSize() << "\n";
    auto tt = v.getSize2();
    const int ttt = v.getSize2();
    tt = 90;
    cout << ttt ; 
}
