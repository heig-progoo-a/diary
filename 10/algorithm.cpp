#include <algorithm>
#include <vector> 

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};
    std::for_each(v.begin(), v.end(), [](int &x) { x++; });
}