#include <iostream>
#include <algorithm> 
#include <ranges> 
#include <functional>

template <typename T>
struct Node {
    T value;
    Node* next;
    Node(T value, Node* next) : value{value}, next{next} {}
};

template <typename T>
class Iterator {
    public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = T;
    using node_type = Node<T>*;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;
    explicit Iterator(node_type ptr) : m_ptr(ptr) {}
    Iterator& operator++() { m_ptr = m_ptr->next; return *this; }
    reference operator*() const { return m_ptr->value; }
    pointer operator->() const { return &m_ptr->value; }
    auto operator==(const Iterator& other) const { return m_ptr == other.m_ptr; }
    auto operator!=(const Iterator& other) const { return m_ptr != other.m_ptr; }
    private:
    node_type m_ptr;
};

template<typename T>
class LinkedList {
    Node<T> *head, *tail;
    public:
    LinkedList() : head{nullptr}, tail{nullptr} {}
    ~LinkedList() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }    
    void push_back(T value) {
        auto* node = new Node<T>(value, nullptr);
        if (head == nullptr) { head = node; tail = node;} 
        else { tail->next = node; tail = node;}
    }
    auto begin() const { return Iterator<T>(head); }
    auto end() const { return Iterator<T>(nullptr); }
};

int main() {
    LinkedList<int> list;
    for (int i = 0; i < 10; i++) { list.push_back(i); }
    for (auto &v: list) { std::cout << v << std::endl; }

    //std::ranges::for_each(list, [](int &n){ n *= 2; });
}