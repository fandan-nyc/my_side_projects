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
        // to leverage the for(auto& x: vectorList){}
        // we need to define begin and end;
};

template<typename T> 
T* begin(Vector<T>& vector){
    return vector.length() == 0 ? nullptr : &vector[0];
}

template<typename T> 
T* end(Vector<T>& vector){
    return begin(vector) + vector.length();
}


int main(){
    Vector<double> doubleVector = Vector<double>(4);
    doubleVector[2] = 10.2;
    cout << doubleVector[2] << endl;
    
    Vector<int> intVector = Vector<int>(4);
    intVector[1] = 10.22;
    cout << intVector[1] << endl;
    
    for(auto& v: doubleVector){
        cout << v << endl;
    } // here we override begin and end in the std::begin / std::end
    
}
