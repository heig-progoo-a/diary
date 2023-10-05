#include <string>
// "I want to crete a circle with radius 42..."
// "(30, 2,1)"
// "<circle radius=20><point x=23, y=44/></circle>"

// Design Pattern : abstract factory method

struct Circle {
    float radius, x, y;
    Circle(float radius, float x, float y) : radius(radius), x(x), y(y) {}
    Circle(float x, float y) : radius(0), x(x), y(x) {}
    Circle() : radius(0), x(0), y(0) {}
    Circle(std::string description) {
        //...
        //radius = ...
    }

    static Circle createCircleFromString(std::string description) {

    }

    static Circle createMagicCircle() {
        return Circle(42, 23, 23);
    }
};

int main() {
    Circle prout = Circle::createCircleFromString("jklkjkjl");

}