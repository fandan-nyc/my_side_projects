#pragma once 
#include "Pizza.h"

class ChicagoBeefPizza : public Pizza {

public:
    std::string getDescription() override {
        return "chicago beef pizza";
    }
};