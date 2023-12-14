#include <iostream>
#include <vector>

struct Foo {
    int u;
    Foo(int u) : u{u} { std::cout << "Foo()\n"; }
    Foo(const Foo&) { std::cout << "Foo(const Foo&) [copy constructor]\n"; }
    ~Foo() { std::cout << "~Foo()\n"; }
};

void node(const int u, int i) { // void node(Foo foo, int i) {
    static std::vector<Foo> heap;
    if (i == 0) {
        heap.emplace_back(u); 
        return;
    }
    node(u, i - 1);
}

int main() {
    node(42, 10);
    std::cout << "Done\n";
}