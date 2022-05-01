#include "WeatherData.h"
#include "Observer.h"

void WeatherData::registerObserver(Observer* observer){
    observers.insert(observer);
}

void WeatherData::removeObserver(Observer* observer){
    observers.erase(observer);
}

void WeatherData::notifyObservers(){
    for(auto ob: observers){
        ob ->updateData(this -> temperature, this -> pressure);
    }
}

void WeatherData::getObserverCount() const {
    std::cout <<  "observers count: " <<  observers.size() << std::endl;
}

void WeatherData::updateData(float temperature, float pressure){
    this -> temperature = temperature; 
    this -> pressure = pressure;
    notifyObservers();
}