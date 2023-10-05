/**
 * Vous avez une classe Animal qui a un nom et un age;
 * Vous avez un chat et un lapin qui sont des animaux
 * Vous réalisez un petit programme qui illustre cet exemple en C++;
 *
 * cat.speak() // A 🐱 is speaking
 * rabbit.speak() // A 🐇 is speaking
 *
 */
#include <iostream>

class Animal {
    std::string name;
    protected:
    int age;
    public:
    Animal(std::string name) : name{name}, age(0) {}
    void speak() { std::cout << "An animal is speaking\n"; }
    void eat() { std::cout << "An animal is eating\n"; }
    void birthday() { age++; }
    std::string get_name() { return name; }
};

class Cat : public Animal {
    int lifes;
    public:
    Cat(std::string name) : Animal{name}, lifes{7} {}
    void revive() { this->age = 0; lifes--; }
    void speak() { std::cout << "A 🐱 named " << get_name() << " is speaking\n"; }
};
