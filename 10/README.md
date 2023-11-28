# Semaine 10/16

- [ ] Itérateurs
- [ ] Copie profonde

## Itérateurs

```c++
char array[30];
for (int i=0; i<30; i++) {
    std::cout << array[i];
}

std::array<char, 30> array;
for (auto it=array.begin(); it != array.end(); it++) {
    std::cout << it;
}
```

## Exercice

Implémenter une liste simplement chaînée sur des entiers.
Créer un itérateur séquentiel sur cette liste chaînée. 

```cpp
class Node { int value; Node* next;}

class LinkedList {
    class Node {
        int value;
        Node* next;
    };
    Node* head;
    Node* tail;
};
```

L'objectif est de pouvoir faire : 

```cpp
int main() {
    LinkedList list;
    for (int i = 0; i < 10; i++) { list.push_back(i); }
    for (auto &v: list) { std::cout << v << std::endl; }
}
```

Correction dans [linked-list.cpp](linked-list.cpp)
