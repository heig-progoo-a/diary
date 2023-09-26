
struct Foo {
    int u;
    // 1. Constructeur par défaut
    // 2. Operateur d'affectation par défaut
    // 3. Destructeur par défaut
    // 4. Opérateur par copie

    // /!\ Attention toute déclaration additionnelle de constructeur
    // Supprime le constructeur par défaut.
    Foo(int v ) : u(v) {}
};

int main() {
    Foo foo;
    Foo bar;
    bar.u = 42;
    foo = bar;
    Foo baz = foo;
}