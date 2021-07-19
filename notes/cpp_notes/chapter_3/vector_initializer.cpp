#include <iostream>

using namespace std;
class Vector {
public:
    Vector(std::initializer_list<double> lst): ele{new double[lst.size()]}, size{static_cast<int>(lst.size())} {
        copy(lst.begin(), lst.end(), ele);
    }
    
    Vector(int s) {
        if (s < 0) {
            throw length_error("vector length cannot be negative");
        }
        ele = new double[s];
        size = s;
    }
        
    
    ~Vector() {
        cout << "end";
        delete[] ele;
    }
    
    double& operator[](int pos) {
        return ele[pos];
    }
    
    int getSize() const {
       // this -> size = 1; will not work
        return this -> size;
    }
    
private:
    double* ele;
    int size;
};


int main(){
    Vector v = {1,2,3.0};
    const int len = v.getSize();
    cout << len;
    cout << v[1];
    
    v =  Vector(10);
    const int len2 = v.getSize();
    cout << len2;
}
