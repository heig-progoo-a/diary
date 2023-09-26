#include <iostream>

struct Point {
    double x; 
    double y;

    Point(double x, double y) : x(x), y(y) {}
    Point(double d) : x(d), y(d) {}

    void display() {
        std::cout << "P(" << x << ", " << y << ")\n";
    }
};

int main() {
    Point p(23,42);
    Point q(44);
    p.display();
    q.display();
}