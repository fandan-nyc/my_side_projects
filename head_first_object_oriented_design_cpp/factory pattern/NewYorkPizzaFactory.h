#pragma once 
#include "Pizza.h"
#include "NewYorkCheesePizza.h"
#include "NewYorkPizza.h"
#include <memory>

class NewYorkPizzaFactory : public PizzaFactory {
public:
    std::unique_ptr<Pizza> createPizza(std::string pizzaType) override {
        if(pizzaType == "ny pizza"){
            return std::make_unique<NewYorkPizza>();
        }else if (pizzaType == "ny cheese pizza"){
            return std::make_unique<NewYorkCheesePizza>();
        }
        return nullptr;
    };
};