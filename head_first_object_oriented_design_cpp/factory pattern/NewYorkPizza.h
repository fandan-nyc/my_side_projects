#pragma once

#include "Pizza.h"
#include <iostream>

class NewYorkPizza: public Pizza {
public:
    std::string getDescription() override;
private:
    std::string name = "new york pizza";
    std::string source = "new york source";
};