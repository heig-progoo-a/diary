# Programmation orientée objets

## Historique

- Invention de la programmation orientée objet
Inventé en 1969 (Simula 67): classes polymorphisme et héritage. Le Smalltalk-80 est le premier langage à avoir intégré la programmation orientée objet.

- Invention du C++ 
Bjarne Stroustrup. 1983. C avec des classes. 1985. C++. 

- Normes ?
ISO/IEC 14882:2011, ISO/IEC 14882:2014, ISO/IEC 14882:2017, ISO/IEC 14882:2020

## C'est quoi la différence entre C et C++ ?

Paradigme du langage C : procédural, impératif
Paradigme du langage C++ : orienté objet, procédural, impératif

```c++
#include <stdio.h>
int main() {
    printf("Hello world\n");
}
```

## Namespaces

Les namespaces sont des conteneurs de variables et de fonctions. Ils permettent
d'éviter les collisions de noms.

```c++
#include <iostream>

using namespace toto;

namespace toto {
    int a = 1;
    int b = 2;
}

namespace tata {
    int a = 3;
    int b = 4;
}

int main() {
    std::cout << toto::a << std::endl;
    std::cout << tata::a << std::endl;

    // using namespace toto, la variable a correspond à celle de toto
    std::cout << a;

    int cout = 42;
    std::cout << cout;
}
```

## Structures

En C++ il est possible de définir des conteneurs de données auxquel on associe
des actions. On appelle cela des structures ou des classes. 

Ainsi il est possible de définir une classe "Chien" qui comporte une action "Aboyer".
On peut ensuite instancier un chien "rex" et le faire aboyer avec "rex.aboyer()".

## Exercice 

- Créer un fichier cat.cpp
- Créer une structure `Cat`
- Associer un attribut (variable) `name` à la structure `Cat`
- Associer un attribut `age` à la structure `Cat`
- Associer les fonctions :
  - `say` qui affiche le nom du chat suivi de "Miaou"
  - `birthday` qui incrémente l'âge du chat de 1
- Dans le main, créer deux chats, et faire dire "Miaou" à chacun d'entre eux