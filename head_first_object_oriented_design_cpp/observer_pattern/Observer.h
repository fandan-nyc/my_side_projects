#pragma once
#include <iostream>
class WeatherData;
class Observer {
public:
    Observer(WeatherData* weatherData);
    virtual void display() const = 0;
    void registerSelf();
    void deregisterSelf();
    void updateData(float temperature, float pressure);
protected:
    float temperature = 0;
    float pressure = 0;
    WeatherData* weatherData;
};