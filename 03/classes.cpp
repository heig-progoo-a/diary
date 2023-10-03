#include <iostream>

class Cat { // Tout est privé par défaut
    int age;
    public:
    Cat(int age) : age(age) {}
    void eat() {}
};

struct Dog { // Tout est public par défaut
    Dog(int age) : age(age) {}
    void eat() {}
    int get_age() { return age; }
    private:
    int age;
};

int main() {
    Cat cat(42);
    Dog dog(23);
    std::cout << dog.get_age() << std::endl;
}