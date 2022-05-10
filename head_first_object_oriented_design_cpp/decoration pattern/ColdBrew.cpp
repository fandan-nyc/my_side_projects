#include "ColdBrew.h"
#include <string>

const std::string ColdBrew::getDescription() const {
    return this -> description;
}

float ColdBrew::getCost() const {
    return this -> cost;
}