#include <iostream>
#include "Beverage.h"
#include "ColdBrew.h"
#include "Espresso.h"
#include "Mocha.h"
#include "milk_2_pct.h"
#include <memory>

using namespace std;

int main(){
    unique_ptr<Beverage> cb = std::make_unique<ColdBrew>();
    unique_ptr<Beverage> cb_mocha = std::make_unique<Mocha>(move(cb));
    unique_ptr<Beverage> cb_mocha_milk2pct = std::make_unique<Milk2Pct>(move(cb_mocha));
    cout << cb_mocha_milk2pct -> getCost() << endl;
    cout << cb_mocha_milk2pct -> getDescription() << endl;
}