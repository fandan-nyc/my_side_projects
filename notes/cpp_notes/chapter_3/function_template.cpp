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
        
        const int length() const {
            return size;
        }
        
        T* begin(){
            return size == 0? nullptr: &ele[0];
        }
        
        T* end() {
            return begin() + size;
        }
        // to leverage the for(auto& x: vectorList){}
        // we need to define begin and end;
};

template<typename Vector, typename Value>
Value& sum(Vector v, Value& init) {
    for(auto& i: v){
        init += i;
    }
    return init;
}

int main(){
    Vector<int> intVector = Vector<int>(4);
    intVector[0] = 10;
    intVector[1] = 20;
    intVector[2] = 30;
    int init = -1;
    cout << sum(intVector, init)  << endl;
    cout << init  << endl;
}
