
struct Foo {
    float value;
    // Postincrement
    auto operator++(int) { 
        auto tmp = *this;
        value = value + 1;
        return tmp;
    }

    // Precrement
    auto operator++() {
        value = value + 1;
        return *this;
    }

    operator int() { return value; }
    operator float() { return value; }
};



int main() {
    for (Foo i = 0; i < 20; i++) {}
    for (Foo i = 0; i < 20; ++i) {}
}