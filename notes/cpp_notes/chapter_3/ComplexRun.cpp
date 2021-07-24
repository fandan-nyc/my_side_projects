#include <iostream> 
#include "Complex.h"

using namespace std;

Complex operator+( Complex a,  Complex b) {
    return a += b;
}

int main(){
    
    Complex x {1, 2};
    Complex y {3.4}; 
    x.real(10.11);
    x.img(12.34);
    Complex z = x + y;
    
    x.print();
    z.print();
    x.print();

    // to run this 
    // g++ ComplexRun.cpp Complex.cpp
    // ./a.out
}
