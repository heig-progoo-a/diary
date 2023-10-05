# Semaine 03/16

- [ ] Mot clé `class` qui est pareil que `struct` mais en privé
- [ ] Mots clés : `private`, `public` et (`protected`)
- [ ] Héritage simple on écrit par exemple `class Cat : public Animal`
- [ ] Streams ont des buffers d'entrée et de sortie et qu'on peut utiliser: 
  - [ ] `.putback()`
  - [ ] `.peek()`
  - [ ] `.ignore()`
  - [ ] ...
- [ ] Compilation séparée (voir exemples cpp)
- [ ] Listes d'initialisations

## Listes d'initialisation

```cpp

class Vecteur {
  int a, b;
  Vecteur(int a, int b) : a(a), b(b) {}
};

class Toto {
  int a;
  Vecteur b;
  Point c;
  Tata d;
  Toto() : a(), b(), c(), d() {}
  Toto(int a, int x, int y) : a{a + 2}, b(x, y), c(y, x), d(a + x * y) {}
};
```

## Narrowing

```cpp
struct Toto  
{
    int a;
    Toto(int a) : a{a} {}
};

int main() {
long long v = 748279837294847329;
  Toto toto{v};
}
```

## Allocation dynamique

```cpp
class Toto {
  int a;
} 

int main() {
  Toto toto{}; // Stack
  Toto *p = new Toto(); // Heap
  delete p;
}
```

## Liste chaînée

```cpp
class Element {
  int value;
  Element(int value) : value{value} {}
};
class List {
  Element *head;
  Element *tail;
  size_t size;
  public:
  void push(int value) {
    Element *new_element = new Element(value);
    tail->next = new_element;
    tail = new_element;
    size++;
  }
  int pop_front() {
    int value = head.value;
    Element *next = head.next;
    delete head;
    head = next;
    return value;
  }

  ~List() {
    while(head != tail) {
      Element *next = head->next;
      delete head;
      head = next;
    }
  }
};

void foo() {
  List list;
  list.push(4); list.push(8);
}
int main() {
  foo()
}
```

## Exercice 

Vous avez une classe Animal qui a un nom et un age;
Vous avez un chat et un lapin qui sont des animaux
Vous réalisez un petit programme qui illustre cet exemple en C++;

cat.speak() // A 🐱 is speaking
rabbit.speak() // A 🐇 is speaking

