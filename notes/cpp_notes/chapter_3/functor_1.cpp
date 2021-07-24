#include <iostream>

using namespace std;
template<typename Value> 
class LessThan{
    private:
        Value curr;
    public:
        LessThan(Value value): curr{value}{};
        
        bool operator()(Value inputValue){
            return inputValue < curr;
        };
};

int main(){
    LessThan<int> lti {1};
    LessThan<std::string> lts {"abc"};
    cout << lti(10) << endl;
    cout << lti(-2) << endl;
    cout << lts("xyz") << endl;
    cout << lts("ab") << endl;
}
