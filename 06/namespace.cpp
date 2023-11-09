
#include <cmath> 

using namespace std;

// Écrase la fonction max de cmath, donc pas bien...
int max(int a, int b) { return a > b ? a : b; }

int main() {
    std::max() // Bonne approche d'utiliser le préfix std
}