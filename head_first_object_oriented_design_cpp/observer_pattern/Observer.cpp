#include "WeatherData.h"
#include "Observer.h"
#include <iostream>
//#include "WeatherData.h"

using namespace std;
Observer::Observer(WeatherData* weatherData): weatherData{weatherData}{};

void Observer::deregisterSelf(){
    this -> weatherData -> removeObserver(this);
}
void Observer::registerSelf(){
    this -> weatherData -> registerObserver(this);
}
void Observer::updateData(float temperature, float pressure){
    this -> temperature = temperature;
    this -> pressure = pressure;
}