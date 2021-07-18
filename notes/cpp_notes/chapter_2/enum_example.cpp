#include <iostream> 

enum Color {red=3, blue, green};

enum class TrafficLight {red=99, yellow=101, green=42} ;

TrafficLight& operator++(TrafficLight& t) {
    // prefix increment for enum class
    switch(t){
        case TrafficLight::red:
            return t = TrafficLight::green;
        case TrafficLight::yellow:
            return t = TrafficLight::red;
        case TrafficLight::green:
            return t = TrafficLight::yellow;
        default:
            throw "traffic light color does not exist";
    }
}

std::ostream&  operator<<(std::ostream& cout, TrafficLight& t) {
    // prefix increment for enum class
    switch(t){
        case TrafficLight::red:
            return cout << "red";
        case TrafficLight::yellow:
            return cout << "yellow";
        case TrafficLight::green:
            return cout << "green";
        default:
            throw "traffic light color does not exist";
    }
}

Color& operator++(Color& t) {
    // prefix increment for enum
    switch(t){
        case Color::red:
            return t = Color::blue;
        case Color::blue:
            return t = Color::green;
        case Color::green:
            return t = Color::red;
    }
}


int main() {
    auto x = Color::red;
    std::cout << x;
    ++x;
    std::cout << x;
    
    TrafficLight tl = TrafficLight::green;
    ++tl;
    std::cout << tl;
}
