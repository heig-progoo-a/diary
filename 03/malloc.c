#include <stdlib.h>

static volatile int *p;
int main() {
    p = malloc(sizeof(int) * 10000); // Heap
    free(p);
}
