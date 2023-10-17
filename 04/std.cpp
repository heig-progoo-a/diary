#include <iostream>

#include <vector> 

int main() {
    std::vector<int> v;
    std::cout << v.capacity() << std::endl;
    v.push_back(4);
    std::cout << v.capacity() << std::endl;
    v.push_back(8);
    std::cout << v.capacity() << std::endl;
    v.push_back(15);
    std::cout << v.capacity() << std::endl;
    v.push_back(16);
    std::cout << v.capacity() << std::endl;
    v.push_back(23);
    std::cout << v.capacity() << std::endl;
    v.push_back(42);
    std::cout << v.capacity() << std::endl;

    for (int i = 0; i < 10000; i++) {
        v.push_back(i);
        std::cout << v.capacity() << std::endl;
    }                
}