#include <iostream>

struct Dog {
    int age; 
    int weight;

    void bark() {
        if (weight > 10)
            std::cout << "Wrrrroooooffff!" << std::endl;
        else 
            std::cout << "Yip!" << std::endl;
    }
};

int main() {
    Dog rex(10, 15);
    Dog fluffy(7, 4);

    rex.bark();
    fluffy.bark();
}