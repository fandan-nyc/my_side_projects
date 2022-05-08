#pragma once 
#include <memory>
#include "Flyable.h"
#include "Quackable.h"

class Duck{
public:
    Duck(std::unique_ptr<Flyable> flyableBehavior, std::unique_ptr<Quackable> quackableBehavior);
    void quack();
    void fly();
    virtual void display(); 
    
    void setFlyBehavior(std::unique_ptr<Flyable> newFlyBehavior){
        this -> flyableBehavior = move(newFlyBehavior);
    }
    
private:
    std::unique_ptr<Flyable> flyableBehavior;
    std::unique_ptr<Quackable> quackableBehavior;
    
};