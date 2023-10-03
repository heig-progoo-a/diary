#include <iostream>
using namespace std;
struct Foo {
    Foo() { cout << "Foo\n"; }
    Foo(Foo &foo) { cout << "Copy Foo\n";}

    Foo& operator=(Foo &other) { cout << "Assignment\n"; return *this;}
    
    void use() { cout << "use Foo\n"; }
    void view() const { cout << "view Foo\n"; }
    ~Foo() { cout << "~Foo\n"; }
};

void bar(const Foo &a) {
    a.view();
}

int main() {
    Foo foo; // Constructeur par défaut
    bar(foo); // (par référence)
    cout << "---\n";
    Foo babar = foo; // Constructeur par copie
    babar = foo; // Assignement operator
}