#include <iostream>

using namespace std;

template <typename T>
class Vector {
    private:
        T* ele; 
        int size;
    public:
        Vector(int sizeV): size{sizeV}, ele{new T[sizeV]}{};
        
        ~Vector(){
            delete ele;
        }
        
        const T& operator[](int i)const{
            return ele[i];
        }
        
        T& operator[](int i){
            return ele[i];
        }
};

int main(){
    Vector<double> doubleVector {4};
    doubleVector[2] = 10.2;
    cout << doubleVector[2] << endl;
    
    Vector<int> intVector {10};
    intVector[1] = 10.22;
    cout << intVector[1] << endl;
    
}
