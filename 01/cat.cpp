#include <iostream>
#include <string>
struct Cat {
    std::string name;
    int age;

    Cat(std::string _name, int _age) {
        name = _name;
        age = _age;
    }

    void birthday() { age++; }
    void say() { std::cout << name << ": Meow!" << std::endl;}
};

int main() {
    Cat a("Barsik", 5);
    Cat b("Felix", 7);
    a.say();
    a.birthday();
    b.say();
    std::cout << a.age << std::endl;
}