#include <iostream>
#include <exception>

class MyException : public std::exception {
    std::string msg;
    int a, b;
    public:
    MyException(std::string msg, int a, int b) : msg{msg}, a{a}, b{b} {}
    std::string what() {
        return msg + std::to_string(a) + " " + std::to_string(b);
    }
};

int foo() {
    std::cout << "Begin of foo\n";
    throw MyException("Oops", 23, 42);
    std::cout << "End of foo\n";
};

int main() 
{
    std::cout << "Begin\n";
    try { foo(); } 
    catch (std::out_of_range &e) { 
        std::cout << "Message lisible pour l'utilisateur\n"; 
        std::cout << "Message détaillé: " << e.what();
    }
    catch (std::exception &e) {
        std::cout << "Autre exception\n";
        std::cout << e.what();
    }
    std::cout << "End\n";
}