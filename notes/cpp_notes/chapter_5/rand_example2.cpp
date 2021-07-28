#include <random>
#include <iostream>

using namespace std;

class Rand_int {
    public:
        Rand_int(int low, int high): dis{low, high}{};
        
        int operator()(){
            return dis(eng);
        }
    private:
        default_random_engine eng ;
        uniform_int_distribution<> dis;
};

int main(){
    
    cout << Rand_int(1, 10)() << endl;
}
