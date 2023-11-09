#include <pair>

using Point = std::pair<int, int>;

class Element {
    Point p;
    Element(Point p) : p{p} {}
};

class Ball : public Element {
    Ball(Point p) : Element{p} {}
    
}