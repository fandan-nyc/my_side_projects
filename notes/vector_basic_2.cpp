#include <iostream>

using namespace std;
class Vector {
public:
    Vector(int s) :ele {new double[s]}, size {s} {
    };
    int getSize() const {
       // this.size = 1;
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
    cout << v.getSize2();
    
}
