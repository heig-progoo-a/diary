

typedef struct Toto {
    int i;
    Toto() {
        i = 0;
    }
} Toto;


int main() {
    Toto u;
    printf("%d\n", u.i);
}