
#include <cmath>

template <typename T>
struct ProxyLength {
    T squared;
    ProxyLength(T squared) : squared{squared} {}
    operator T() { return sqrtf(squared); }
    bool operator<(const auto &other) {
        return squared < other*other;
    } 
};

template <typename T>
struct Foo {
    T x, y;
    ProxyLength<T> distance() {
        return ProxyLength(x*x + y *y);
    }
};

int main() {
    Foo<float> foo; 
    float d = foo.distance();
    if (foo.distance() < 30)  {} else {}
    if (30 > foo.distance())  {} else {}
}