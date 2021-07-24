#include <iostream>
#include "Complex.h"

using namespace std;

Complex::Complex(double real, double img): realNum{real}, imgNum{img} {};

Complex::Complex(double real): realNum{real}, imgNum{0} {};

Complex::Complex(): realNum{0}, imgNum{0} {};

double Complex::real() const {
    return this -> realNum;
}

double Complex::img() const {
    return this -> imgNum;
}

void Complex::real(double value) {
    this-> realNum = value;
}

void Complex::img(double value) {
    this -> imgNum = value;
}

Complex& Complex::operator+=(const Complex& value) {
    this -> realNum += value.real();
    this -> imgNum += value.img();
    return *this;
}


Complex& Complex::operator-=(const Complex& value) {
    this -> realNum -= value.real();
    this -> imgNum -= value.img();
    return *this;
}

void Complex::print() const{
    cout << this -> real() << endl;
    cout << this -> img() << endl;
}
