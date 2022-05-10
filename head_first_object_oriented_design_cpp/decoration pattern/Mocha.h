#pragma once 
#include "CondimentDecorator.h"
#include <string>
#include "Beverage.h"
#include <memory>

class Mocha : public CondimentDecorator {
public:
    Mocha(std::unique_ptr<Beverage> beverage);
    const std::string getDescription() const;
    float getCost() const;
    
private:
    const std::string description = "mocha";
    float cost = 5.6;
    std::unique_ptr<Beverage> beverage_;
};
