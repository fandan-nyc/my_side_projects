#include "milk_2_pct.h"
#include <string> 

 const std::string Milk2Pct::getDescription() const {
     return this -> beverage_ -> getDescription() + ", " + this -> description;
 }
 
float Milk2Pct::getCost() const {
    return this -> beverage_ -> getCost() + this -> cost;
}
