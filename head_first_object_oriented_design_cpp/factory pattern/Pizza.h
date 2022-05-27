#pragma once 
#include <string> 

class Pizza {
public:
    Pizza() = default;
    virtual std::string getDescription();
private:
    std::string name;
    std::string source;
};