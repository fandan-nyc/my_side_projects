#include "WoodenDuck.h"
#include "Flyable.h"
#include "Quackable.h"
#include <memory>
#include <iostream>

using namespace std;
WoodenDuck::WoodenDuck(unique_ptr<Flyable> flyableBehavior, unique_ptr<Quackable> quackableBehavior):
    Duck{move(flyableBehavior), move(quackableBehavior)} {};

void WoodenDuck::display(){
    cout << "wooden duck display" << endl;
}