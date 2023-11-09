#include <iostream>
#include <memory> 

class Element {
    std::shared_ptr<int> value;

    Element *next;
    public: 
    Element(std::shared_ptr<int> value) : value{value} {}
};

// RAII (Resource Acquisition is Initialization)
class LinkedList {
    public:
    void push(std::shared_ptr<int> value) {
        Element *el = new Element(value); 
    }
    ~LinkedList() {
        // Delete all allocated elements
    }
};

void dataProcessing(LinkedList &l) {
    std::shared_ptr<int> p = std::make_shared<int>(42);
    for(int i = 0; i < 10 ; i++)
        l.push(p); // Allocation dynamique
    delete p;
}
int main() {
    LinkedList l;
    dataProcessing(l);
}