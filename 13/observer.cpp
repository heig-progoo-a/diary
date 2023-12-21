#include <iostream>
#include <vector> 

class Subscriber {
    public:
    virtual void notify(std::string message) = 0;
};

struct Person : public Subscriber {
    std::string name;
    void happy() { std::cout << name << " est content, il a reçu la newsletter\n"; }
    public:
    Person(std::string name) : name{name} {}
    void notify(std::string message) override { happy();
    std::cout << "C'est une bonne nouvelle que: " << message << "\n"; }
};


class Newsletter {
    std::vector<Subscriber*> subscribers;
    std::vector<std::string> news;
public:
    void publish(std::string breakingNews) { 
        news.push_back(breakingNews); 
        notifySubscribers(breakingNews);
    } 
    void subscribe(Subscriber *subscriber) { subscribers.push_back(subscriber); }
private:
    void notifySubscribers(std::string breakingNews) {
        for (auto &subscriber : subscribers) {
            subscriber->notify(breakingNews);
        }
    }
};


int main() {
    Newsletter newsletter;

    Person bob("Bob");
    Person alice("Alice");
    newsletter.subscribe(&bob);
    newsletter.subscribe(&alice);

    while(true) {
        std::string breakingNews;
        std::getline(std::cin, breakingNews);
        newsletter.publish(breakingNews);
    }
}