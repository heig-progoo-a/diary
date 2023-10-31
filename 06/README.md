# Semaine 06/10

- Ca date de quand ? 80-90
- C'est qui qui a inventé ? Stroustrup
- C'est quoi l'overlap avec le C ? 99% du C
- Le C++ apporte quels concepts ? 
  - Orienté Objets
  - Objet
  - Classe
    - Attributs
    - Methodes
      - Publiques
      - Privées
      - Protégées
    - Friend
  - Namespaces
  - Polymorphisme
    - Static (déterminé à la compilation)
      - Surcharge paramétrique
      - Templates
    - Dynamique (déterminé à l'exécution)
      - Pas encore vu pour l'instant
  - STL (Standard Template Library)
    - Conteneur Séquentiels
      - vector
      - array
      - deque
      - list
      - forward_list
      - pair
  - Héritage
    - Problème du diament et comment le résoudre avec une classe virtuelle
    - Interface
    - Methodes vrituelles (`virtual` et `override`)
    - Methodes virtuelles pures (`= 0`)
  - Lambdas
    - Syntaxe `[](){}`
    - Capture tout le contexte local par copie `[=](){}`
    - Capture tout le contexte local par référence `[&](){}`
    - S'utilise souvent avec `std::function<type(type var)>name`
  
## Methode virtuelle 

C'est une méthode qui est destinée à être surchargée par une classe dérivée
et dont ont souhaite créer une table virtuelle (vtable) pour appeler la bonne méthode de la classe dérivée lorsque l'on a du polymorphisme

```cpp
#include <vector>

class Animal {
    virtual void draw() = 0;
}

class Cat : public Animal {
    void draw() override { // Le override est optionnel
        std::cout << "Un chat\n";
    }
}
int main() {
    vector<Animal*> animals;
    for(auto *animal : animals) {
        animals->draw();
    }
}
```


## Class abstraite

C'est une classe qui contient au moins une methode virtuelle

- Elle n'est pas instantiable
  
## Methode virtuelle pure

C'est une méthode virtuelle (avec le mot clé `virtual`) qui ne possède aucune implémentation. On l'écrit avec `=0`

## Interface

C'est une classe qui ne contient que des méthodes virtuelles pures

- Elle n'est pas instantiable
- Elle est utilisée comme "contrat" pour une autre classe


## Scope

```cpp
class Foo {
    protected:
    int pro;
    private: 
    int pri;
    public:
    int pub;
};

class Bar : public Foo {
    void method() {
        /*
        pro est accessible
        pri n'est pas accessible
        pub est accessible
        */
    }
}
```

## Friend

C'est de rendre accessible les methodes et attributs d'une classe
par une autre classe sans héritage

```cpp
class Bar; // Déclaration en amont

class Foo {
    protected:
    int pro;
    private: 
    int pri;
    public:
    int pub;

    friend class Bar; // Autorise Bar à accéder aux éléments privés de Foo
};

class Bar {
    Foo &foo;
    Bar(Foo &foo) : foo{foo} {}
}
```

## Namespaces

Conteneur à classes/fonctions et objets

- L'accès se fait avec l'opérateur `::`
- `using namespace name;` Importe dans l'espace de nom courant 

```cpp
namespace MonNamespace {
    int toto;
}
```

## Templates

```c
#define TOTO(T) T toto(T b) { \
    T a = b; \
    return a; \
}

TOTO(int)
TOTO(double)
```

```cpp
template <class T>  // class ou typename c'est pareil
T toto(T a) {
    T b = a;
    return b;
}
```