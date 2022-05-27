#pragma once 
#include "Pizza.h"
#include <memory> 
class PizzaFactory {
public:
   virtual std::unique_ptr<Pizza> createPizza(std::string pizzaType) = 0;
};