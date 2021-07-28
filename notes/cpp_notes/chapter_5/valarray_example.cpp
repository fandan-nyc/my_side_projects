#include <iostream>
#include <valarray>

using namespace std;

int main(){
    valarray<int> a {1,2,3};
    valarray<int> b {4,5,6};
    a += b * 2;
    for(auto& i: a){
        cout << i << endl;
    }
}
