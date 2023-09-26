# Semaine 02/16

On a vu que : 

- En C++ on peut surcharger les opérateurs
- Et donc spécialiser le comportement des objets
- On a vu qu'on avait les même structure qu'en C mais qu'on les appelle des classes
- Parce qu'une classe peut être instanciée. 

## Surcharge (de fonction)

En C++ il est possible d'avoir plusieurs fonctions qui 
ont les mêmes noms mais différents type de paramètres, pour autant
qu'il n'y ait pas d'ambiguité.

```cpp
// Avec des types différents
int add(int a, int b) { return a+b;}
float add(float a, float b) { return a+b;}

// Avec des paramètres différents
void display(int a) { std::cout << a << "\n"};
void display(int a, int b) { std::cout << a << ", "<< b << "\n"};
```

## Constructeur

C'est l'étape entre la classe et son instanciation. 

Le constructeur initialise les attributs de l'instance

```cpp 
// Constructeur avec liste d'initisation
// Le constructeur construit au passage deux instance (age et name)
// Et donc il appelle avant {} ces deux constructeurs
class Animal {
    int age;
    std::string name;
    Animal() : age(0), name("unknown") {}
}

// Constucteur classique (qui a des limitations)
// Moins performante parce que dans tous les cas les constructeurs
// Des attributs sont quand même appelés.
class Animal {
    int age;
    std::string name;
    Animal() {
        age = 0;
        name = "unkown";
    }
}