#include <iostream>
#include <ctime> 

// Une classe abstraite est une classe qui contient au moins une methode 
// virtuelle pure (a.k.a. Une classe qui ne peut pas être instantiée)
// Si toutes les méthodes virtuelles sont pures, il s'agit d'une interface
// Virtuel == `virtual`
// Pure == `= 0`
struct Animal {
    int age;
    virtual void draw() = 0;
    virtual void birthday() {
        age++;
    }
};

struct Mouse : public Animal {
    void eat_cheese() { std::cout << "🐭🧀\n"; }
    void draw() override { std::cout << "🐭\n"; }
    void birthday() override { /* oops */ }
};

struct Cat : public Animal {
    void draw() override { std::cout << "🐱\n"; }
};

int main() {
    Cat cat;
    Mouse mouse;
    Animal *animal;

    if (std::time(nullptr) % 2) 
        animal = &cat;
    else 
        animal = &mouse;
    animal->draw();

    mouse.eat_cheese();

}