#include <iostream>

using namespace std;


class Vector {
    
    public:
        Vector(initializer_list<int> inputValue): 
            size{static_cast<int>(inputValue.size())}, 
            ele{new int[inputValue.size()]}{
                copy(inputValue.begin(), inputValue.end(), ele);
        };
        
        Vector(const Vector& v): size{v.size}, ele{new int[v.size]}{ // copy constructor
            for(int i = 0 ; i < size; i++){
                ele[i] = v[i];
            }
        };
        
        Vector& operator=(const Vector& v){ // copy assignment
            int* tmp = new int[v.size];
            for(int i = 0; i< v.size;i++){
                tmp[i] = v[i];
            }
            delete ele;
            ele = tmp;
            size = v.size;
            return *this;
        };
        
        ~Vector(){
            delete ele;
        }
        
        const int& operator[](int pos) const{
            return ele[pos];
        }
        
        int& operator[](int pos){
            return ele[pos];
        }
        
    private:
        int size;
        int* ele;
    
};

int main(){
    Vector x {1,2,3,4};
    Vector z {x};
    Vector y = x;
    cout << x[2] << endl;
    cout << y[2]  << endl;
    cout << z[2]  << endl;

    x[1] = 10;
    cout << x[1] << endl;
    cout << y[1]  << endl;
    cout << z[1]  << endl;

}
