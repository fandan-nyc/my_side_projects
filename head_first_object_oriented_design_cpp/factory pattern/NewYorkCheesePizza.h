#pragma once 
#include "Pizza.h"

class NewYorkCheesePizza : public Pizza {

public:
    std::string getDescription() override {
        return "new york cheese pizza";
    }
};