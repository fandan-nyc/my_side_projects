#pragma once
#include <string>

class Beverage {
public:
    Beverage() = default;
    virtual const std::string getDescription() const = 0;
    virtual float getCost() const = 0;
};