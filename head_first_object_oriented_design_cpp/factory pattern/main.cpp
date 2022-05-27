#include <iostream> 
#include <memory>
#include "Pizza.h"
#include "PizzaStore.h"
#include "NewYorkPizzaStore.h"

using namespace std;

int main(){
    unique_ptr<PizzaStore> nycPizzaStore = make_unique<NewYorkPizzaStore>();
    nycPizzaStore -> orderPizza("ny pizza");
}
