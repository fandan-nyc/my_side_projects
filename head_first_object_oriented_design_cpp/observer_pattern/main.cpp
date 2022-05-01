#include "WeatherData.h"
#include "Observer.h"
#include "NormalObserver.h"

int main(){
  WeatherData* wd = new WeatherData{};
  Observer* x =  new NormalObserver(wd);
  x -> registerSelf();
  wd -> getObserverCount();
  wd -> updateData(1,2);
  x ->display();
  wd -> updateData(3,4);
  x ->display();
  x -> deregisterSelf();
  wd -> getObserverCount();
  wd -> updateData(5,6);
  x-> display();

}