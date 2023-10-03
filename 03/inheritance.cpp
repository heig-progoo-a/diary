

class Animal {
    int age;
    public:
    void eat();
};

class FelisCatus : public Animal {
    void revive() { }
};

class Cat : public FelisCatus {

};

int main() {
    Cat cat;
    cat.
}