#include <iostream>
#include <vector>

using namespace std;

template<typename Container, typename functor>
void addOne(Container c, functor f){
    int res = 0;
    for(auto& i: c){
        f(i);
    }
};

int main(){
    vector<int> inputValue {1,10,100,3,4,11};
    int x = 10;
    int y = 11;
    cout << "x:" << x << endl;
    cout << "y:" << y << endl;
    cout << "----" << endl;
    addOne(inputValue, [&x](int x){x +=1;});    
    cout << "x:" << x << endl;
    cout << "y:" << y << endl;
    cout << "----" << endl;
    addOne(inputValue, [&](int x){x  +=1;});
    cout << "x:" << x << endl;
    cout << "y:" << y << endl;
    cout << "----" << endl; 
    addOne(inputValue, [&](int x){y  +=1;});
    cout << "x:" << x << endl;
    cout << "y:" << y << endl;
    cout << "----" << endl;
    addOne(inputValue, [=, &y](int x){x += 1; y  +=1;});
    cout << "x:" << x << endl;
    cout << "y:" << y << endl;
    cout << "----" << endl;
    // addOne(inputValue, [](int x){x += 1; y +=1;});
    // cout << "x:" << x << endl;
    // cout << "y:" << y << endl;
    // cout << "----" << endl;
    // does not work since u capture nothing.
}
