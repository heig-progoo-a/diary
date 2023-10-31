#include <iostream>
#include <vector>
#include <functional>

struct Element {
    int value;
    Element(int value) : value{value} {}
    void display() const {
        std::cout << value << " ";
    }
};


int doubleIt(int value) {
    return value * 2;
}

struct Container {
    int i = 0;
    std::vector<Element> elements;
    void append_element() {
        elements.push_back(Element(i++));
    }


    void neighbour(int index, std::function<int(int)>action) {
        if (index > 0 && elements.size() > 1)
            elements[index - 1].value = action(elements[index - 1].value);
        if (index < elements.size() && elements.size() > 1)
            elements[index + 1].value = action(elements[index + 1].value);
    }
    /*
    void neighbourDoubleIt(int index) {
        if (index > 0 && elements.size() > 1)
            elements[index - 1].value = doubleIt(elements[index - 1].value);
        if (index < elements.size() && elements.size() > 1)
            elements[index + 1].value = doubleIt(elements[index + 1].value);
    }
    */
};

int main() {
    Container c;
    for (int i = 0; i < 10; i++) c.append_element();

    c.neighbour(4, doubleIt);
    c.neighbour(5, [](int a){return -a;});
    int sum = 0;
    c.neighbour(5, [&](int a){sum += a; return a;});
    std::cout << sum << std::endl; 

    for (auto &el : c.elements) el.display();

}