#include <iostream>
#include "Duck.h"
#include "WoodenDuck.h"
#include "Flyable.h"
#include "RocketFly.h"
#include "Quackable.h"
#include "Nofly.h"

using namespace std;

int main(){
    unique_ptr<Duck> superDuck = make_unique<WoodenDuck>(move(make_unique<RocketFly>()), move(make_unique<Quackable>()));
    superDuck -> display();
    superDuck -> fly();
    superDuck -> quack();
    superDuck -> setFlyBehavior(move(make_unique<Nofly>()));
    superDuck -> fly();
}