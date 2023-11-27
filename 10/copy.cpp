#include <iostream>
#include <cstring>

class MyClass {
public:
    MyClass(const char* str = "") {
        size = std::strlen(str);
        data = new char[size + 1]; // Allocate heap memory
        std::strcpy(data, str);
    }

    // Copy constructor for deep copy
    MyClass(const MyClass& other) {
        size = other.size;
        data = new char[size + 1]; // Not only copies the pointer, but also the data
        std::strcpy(data, other.data);
    }

    MyClass& operator=(const MyClass& other) {
        if (this == &other) return *this; // Self-assignment check
        delete[] data;
        size = other.size;
        data = new char[size + 1];
        std::strcpy(data, other.data);
        return *this;
    }
    ~MyClass() { delete[] data; }
    void print() const { std::cout << data << std::endl; }

private:
    char* data;
    size_t size;
};

int main() {
    MyClass obj1("Hello");
    MyClass obj2 = obj1; // Deep copy via copy constructor

    obj1.print(); // Prints "Hello"
    obj2.print(); // Also prints "Hello"

    return 0;
}