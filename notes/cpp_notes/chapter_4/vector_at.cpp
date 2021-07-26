#include <iostream>
#include <vector> 

using namespace std;

template<typename T>
class Vec : public  vector<T> {
    
    public:
    using vector<T>::vector; // using constructor from vector 
    
    T& operator[](int i) {
        return vector<T>::at(i);
    }
    
    const T& operator [](int i) const {
        return vector<T>::at(i);
    }
};

int main() {

    vector<int> vectorTest {1,2,3,4};
    cout << vectorTest[10];
    
    Vec<int> test {1,2,3,4};
    cout << test[10];
}
