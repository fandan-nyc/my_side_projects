#pragma once 

#include "Pizza.h"

class ChicagoPizza: public Pizza {
public:
    ChicagoPizza() = default;
    std::string getDescription() override ; 
private:
    std::string name = "chicago pizza";
    std::string source = "chicago source";
};