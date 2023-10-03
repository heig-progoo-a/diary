#include <iostream>
#include <fstream>

void hello(std::ostream &oss117) {
    oss117 << "Hello World" << std::endl;
}

int main() {
    std::ofstream f("toto.txt", std::ios::binary);
    hello(f);
}