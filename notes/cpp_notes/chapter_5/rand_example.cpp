#include <random>
#include <iostream>
#include <functional>

using namespace std;

int main(){
    using my_engine = default_random_engine;
    using my_distribution = uniform_int_distribution<>;
    
    my_engine re {};
    my_distribution one_to_six {1,6};
    
    auto die = std::bind(one_to_six, re);
    
    // another way to write die, in a better way
    auto die2 = std::bind(uniform_int_distribution<>{1,10}, default_random_engine{});
    for(int counter = 0 ; counter < 10; counter ++){
        cout << die2() << endl;
    }
}
