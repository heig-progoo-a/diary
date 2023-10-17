#include <iostream>
#include <vector>

// Une classe abstraite est une classe qui contient au moins une methode 
// virtuelle pure (a.k.a. Une classe qui ne peut pas être instantiée)
// Si toutes les méthodes virtuelles sont pures, il s'agit d'une interface
// Virtuel == `virtual`
// Pure == `= 0`
struct Animal {
    int age;
    virtual void draw() = 0;
    void birthday() {
        age++;
    }
};

struct Mouse : public Animal {
    void eat_cheese() { std::cout << "🐭🧀\n"; }
    void draw() override { std::cout << "🐭\n"; }
};

struct Cat : public Animal {
    void draw() override { std::cout << "🐱\n"; }
};

int main() {
    std::vector<Animal*> animals;

    for(int i = 0; i < 100; i++) {
        if (i%2)
            animals.push_back(new Cat());
        else 
            animals.push_back(new Mouse());
    }

    for(int i = 0; i < 100; i++) {
        animals[i]->draw();
    }
}