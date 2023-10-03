
int foo(int a, int b) {
    return a + b;
}

void foobar(int a, int b, int &sum, int &product) {
    sum = a + b;
    product = a * b;
}

int main() {
    int u, v;
    foobar(23, 42, u, v);
}