#pragma once 
#include "Beverage.h"
#include "CondimentDecorator.h"
#include <memory>
#include <string>

class Milk2Pct : public CondimentDecorator {
public:
    Milk2Pct(std::unique_ptr<Beverage> beverage): beverage_ {move(beverage)} {};
    const std::string getDescription() const;
    float getCost() const;
private:
    const std::string description = "2% milk" ; 
    const float cost = 0.2;
    std::unique_ptr<Beverage> beverage_;
    
};