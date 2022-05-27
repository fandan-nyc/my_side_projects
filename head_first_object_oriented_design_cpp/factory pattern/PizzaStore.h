#pragma once 
#include <iostream>
#include "PizzaFactory.h"

class PizzaStore {
public:
    PizzaStore() = default;
    virtual void orderPizza(std::string type) = 0; 
};
