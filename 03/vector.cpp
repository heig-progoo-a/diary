#include <iostream>
#include <vector>

int main() {
    std::vector<int> v;
    v.push_back(4);
    v.push_back(8);
    v.push_back(15);

    for (int i : v) {
        std::cout << i << "\n";
    }
}