#include <iostream>

using namespace std;


class Vector {
    
    public:
        Vector(initializer_list<int> inputValue): 
            size{static_cast<int>(inputValue.size())}, 
            ele{new int[inputValue.size()]}{
                copy(inputValue.begin(), inputValue.end(), ele);
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
    Vector y = x;
    cout << x[2] << endl;
    cout << y[2]  << endl;
    y[1] = 10;
    cout << x[1] << endl;
    cout << y[1]  << endl;
}
