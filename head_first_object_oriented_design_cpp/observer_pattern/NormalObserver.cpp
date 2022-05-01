#include <iostream>
#include "NormalObserver.h"
#include "Observer.h"

using namespace std;
NormalObserver::NormalObserver(WeatherData* weatherData): Observer{weatherData}{};

void NormalObserver::display() const {
    std::cout << "normal observer display. temperature: "  << this -> temperature << ". pressure: " << this -> pressure << endl;
};