#include <iostream>
#include <functional> 

#if 0
void iterate(int *array, int(*func)(int)) {
   for (int i = 0; i < 10; i++) {
        array[i] = func(array[i]);
   } 
}
#else
void iterate(int *array, std::function<int(int)> func) {
   for (int i = 0; i < 10; i++) {
        array[i] = func(array[i]);
   } 
} 
#endif

int zero(int a) { return 0; }

int mult(int a) { return 10*a; }

int main() {
    int n = 10;
    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    iterate(array, mult);
    iterate(array, [=](int a){return a*n;}); // Fonction annonyme

    int sum;
    iterate(array, [&](int a){ sum += a; return a;}); // Fonction annonyme

    for (int i = 0; i < 10; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}