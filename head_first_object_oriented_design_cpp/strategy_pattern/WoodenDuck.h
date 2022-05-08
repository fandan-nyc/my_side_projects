#pragma once 
#include "Duck.h"
#include <memory>

class WoodenDuck : public Duck {
    public:
        WoodenDuck(std::unique_ptr<Flyable> flyableBehavior, std::unique_ptr<Quackable> quackableBehavior);
        void display();
};