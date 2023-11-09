class Bar; // Déclaration en amont

class Foo {
    protected:
    int pro;
    private: 
    int pri;
    public:
    int pub;

    friend Bar; // Autorise Bar à accéder aux éléments privés de Foo

    // int get_pri(Bar &bar) {
    //     return pri;
    // }
};

namespace MonNamespace {
    int toto;
}

class Bar {
    Foo &foo;
    Bar(Foo &foo) : foo{foo} {
        foo.pri; // Est accessible
        MonNamespace::toto;
    }
};
