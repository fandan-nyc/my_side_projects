#include "Mocha.h"
#include "Beverage.h"
#include <memory>

using namespace std;

Mocha::Mocha(unique_ptr<Beverage> beverage): beverage_{move(beverage)} {};

const std::string Mocha::getDescription() const {
    return beverage_ -> getDescription() + ", " + this -> description;
}

float Mocha::getCost() const{
    return this -> beverage_ -> getCost()+ this -> cost;
}