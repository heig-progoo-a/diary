#include <iostream>

// template <class T>
// class Point {
//     T x;
//     T y;
//     T norm() {
//         return math::sqrt(x*x + y*y);
//     }
// }

template <class T, int N>
class Container {
    public:
    T array[N];
    Container() {
        for (int i = 0; i < N; i++) {
            array[i] = 0;
        }
    }
    T sum() {
        T result = 0;
        for (int i = 0; i < N; i++) {
            result += array[i];
        }
        return result;
    }
};

class Point {
    public:
    int x, y;
    Point(int x=0, int y=0) : x{x}, y{y} {}

    Point operator+(Point &other) {
        return Point(x + other.x, y + other.y);
    }

    Point &operator+=(Point &other) {
        x = x + other.x;
        y = y + other.y;
        return *this;
    }
};

std::ostream &operator<<(std::ostream &os, Point p) {
    os << "(" << p.x << "," << p.y << ")";
    return os;
}

int main() {
    Container<Point, 5> toto;
    toto.array[1] = Point(2,3);
    toto.array[2] = Point(4,5);
    std::cout << toto.sum() << "\n";
}