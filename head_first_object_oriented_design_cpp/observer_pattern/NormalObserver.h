#pragma once
#include "WeatherData.h"
#include "Observer.h"

class NormalObserver : public Observer {
public:
    NormalObserver(WeatherData* weatherData);
    void display() const;
};
