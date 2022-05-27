#pragma once 
#include "Pizza.h"
#include "ChicagoBeefPizza.h"
#include "ChicagoPizza.h"
#include <memory>

class ChicagoPizzaFactory : public PizzaFactory {
public:
    std::unique_ptr<Pizza> createPizza(std::string pizzaType) override {
        if(pizzaType == "chicago pizza"){
            return std::make_unique<ChicagoPizza>();
        }else if (pizzaType == "chicago  pizza"){
            return std::make_unique<ChicagoBeefPizza>();
        }
        return nullptr;
    };
};