#include <iostream>
#include <vector>

struct Foo {
    Foo() { std::cout << "Foo()\n"; }
    Foo(const Foo&) { std::cout << "Foo(const Foo&) [copy constructor]\n"; }
    ~Foo() { std::cout << "~Foo()\n"; }
};

void node(const Foo &foo, int i) { // void node(Foo foo, int i) {
    static std::vector<Foo> heap;
    if (i == 0) {
        heap.push_back(foo); // Constructs a new Foo from the passed reference
        return;
    }
    node(foo, i - 1);
}

int main() {
    node(Foo(), 10);
    std::cout << "Done\n";
}