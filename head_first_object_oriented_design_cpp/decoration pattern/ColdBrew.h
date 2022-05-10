#pragma once 
#include "Beverage.h"
#include <string>


class ColdBrew : public Beverage {
public:
    ColdBrew() = default;
    const std::string getDescription() const;
    float getCost() const;
private:
    const std::string description = "Cold Brew";
    float cost = 3.4;
};