#pragma once 
#include "Flyable.h"

class Nofly: public Flyable {
    void actFly() override; 
};