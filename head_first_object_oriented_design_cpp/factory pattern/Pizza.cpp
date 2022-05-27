#include "Pizza.h"
#include <iostream>

std::string Pizza::getDescription(){
    return  this -> name + " " + this -> source;
}