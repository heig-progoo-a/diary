#include <iostream>
using namespace std;
struct Contact {
    std::string name;
    Contact(std::string name) : name(name) {}
    void set_name(std::string new_name) { name = new_name; }
};
struct Element {
    Contact contact;
    Element *next;
    Element(Contact contact) : contact(contact) {} 
};

int main() {
    Contact c("John");
    Element e(c);
    c.set_name("Michel");
    cout << c.name << endl;
    cout << e.contact.name << endl;
}