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
            cout << "copy constructor is called" << endl;

            for(int i = 0 ; i < size; i++){
                ele[i] = v[i];
            }
        };
        
        Vector& operator=(const Vector& v){ // copy assignment
            cout << "copy assignment is called" << endl;

            int* tmp = new int[v.size];
            for(int i = 0; i< v.size;i++){
                tmp[i] = v[i];
            }
            delete ele;
            ele = tmp;
            size = v.size;
            return *this;
        };
        
        // move constructor
        Vector(Vector&& value): ele{value.ele}, size{value.size}{
            cout << "move constructor is called" << endl;
            value.ele = nullptr;
            value.size = 0;
        }
        // move assignment
        Vector& operator =(Vector&& value){
            cout << "move assignment is called";
            this -> ele = value.ele;
            this -> size = value.size;
            value.ele = nullptr;
            value.size = 0;
        }
        
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
    Vector z {move(x)};
    Vector y  {1};
    y = move(z);
  // result is: 
  // move constructor is called
  // move assignment is called
  // basically, move() gives u the rvalue
}
