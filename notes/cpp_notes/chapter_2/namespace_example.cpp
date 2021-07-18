#include <iostream>

namespace hello {
    namespace world1 {
        const int x = 1;
    }
    
    namespace world2 {
        const int x = 2;
    }
}

const int x = 3;

int main() {
    std::cout << x;
    std::cout << hello::world1::x;
    std::cout << hello::world2::x;
}
