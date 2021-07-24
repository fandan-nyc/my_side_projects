#include <iostream>
#include <vector>

using namespace std;

template<typename Value> 
class LessThan{
    private:
        Value curr;
    public:
        LessThan(Value value): curr{value}{};
        
        bool operator()(const Value& inputValue){
            return inputValue < curr;
        };
};

template<typename Container, typename functor>
int count(Container c, functor f){
    int res = 0;
    for(auto& i: c){
        res += (f(i) ? 1: 0);
    }
    return res;
}

int main(){
    LessThan<int> lti {10};
    vector<int> inputValue {1,10,100,3,4,11};
    cout << count(inputValue, lti);
   
}
