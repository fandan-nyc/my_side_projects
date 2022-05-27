#pragma once 
#include <iostream>
#include "NewYorkPizzaFactory.h"
#include "PizzaFactory.h"
#include <memory>

class NewYorkPizzaStore: public PizzaStore {
public:
    NewYorkPizzaStore() = default;
    void orderPizza(std::string type) override {
    {
        std::cout << "start to order" << std::endl;
        auto pizza = pizzaFactory_ -> createPizza(type);
        std::cout << pizza -> getDescription() << std::endl;
        std::cout << "finish ordering" << std::endl;
    }
    }
private:
    std::unique_ptr<PizzaFactory> pizzaFactory_ = std::make_unique<NewYorkPizzaFactory>();
};
