/*
constructor A
constructor B
constructor A // Construit deux fois
constructor C
constructor D
*/
#include <iostream>
using namespace std;

struct A {
    A() { cout << "constructor A\n"; }
};

struct B : virtual public A {
    B() { cout << "constructor B\n"; }
};

struct C : virtual public A {
    C() { cout << "constructor C\n"; }
};

struct D : public B, public C {
    D() { cout << "constructor D\n"; }
};

int main() {
    D d;
}