#pragma once
#include <set>

class Observer;
class WeatherData {
public:
    WeatherData() = default;
    void registerObserver(Observer* observer);
    void removeObserver(Observer* observer);
    void updateData(float temperature, float pressure);
    void getObserverCount() const ;

private:
    void notifyObservers();
    std::set<Observer*> observers;
    float temperature;
    float pressure;
};