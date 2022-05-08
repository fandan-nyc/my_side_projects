#include "Duck.h"
#include "Flyable.h"
#include "Quackable.h"
#include <iostream>

using namespace std;

Duck::Duck(unique_ptr<Flyable> flyableBehavior, unique_ptr<Quackable> quackableBehavior): 
    flyableBehavior{move(flyableBehavior)}, quackableBehavior{move(quackableBehavior)} {}
    
void Duck::quack(){
    quackableBehavior -> actQuack();
}

void Duck::fly(){
    flyableBehavior -> actFly();
}

void Duck::display(){
    cout << "no display written, please overrride" << endl;
}