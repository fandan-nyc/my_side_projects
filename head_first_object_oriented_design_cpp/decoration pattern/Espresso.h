#pragma once 
#include "Beverage.h"
#include <string>


class Espresso : public Beverage {
public:
    Espresso() = default;
    const std::string getDescription() const;
    float getCost() const;
private:
    const std::string description = "Espresso";
    float cost = 1.2;
};