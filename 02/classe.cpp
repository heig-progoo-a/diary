#include <string>
#include <iostream>

struct Toto {
    const short v;
    int a;
    char c;
    std::string s;

    Toto() : v(0) {
        //v = 0;
        a = 42;
        c = 'v';
        s = "Prout";
    }
    void increment() { a++; }
    void set(char a) { c = a; }
};

int main() {
    Toto u, v;
    u.increment();
    std::cout << u.a << std::endl;
    std::cout << v.a << std::endl;
}