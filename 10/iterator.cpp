#include <iostream>
#include <iterator>
#include <vector>
#include <random>
#include <algorithm>

template <typename T>
class MyIterator {
  public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;
    explicit MyIterator(pointer ptr) : m_ptr(ptr) {}
    MyIterator& operator++() { m_ptr++; return *this; }
    auto operator*() const { return *m_ptr; }
    auto operator->() const { return m_ptr; }
    auto operator==(const MyIterator& other) const { return m_ptr == other.m_ptr; }
    auto operator!=(const MyIterator& other) const { return m_ptr != other.m_ptr; }
private:
    pointer m_ptr;
};

template <typename T>
class RandomOrderIterator {
public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;

    RandomOrderIterator(pointer ptr, size_t size, bool is_end = false)
        : m_data(ptr), m_size(size), m_currentIndex(is_end ? -1 : 0) {
        if (is_end) return;
        for (size_t i = 0; i < size; ++i) indices.push_back(i);
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(indices.begin(), indices.end(), g);
    }

    RandomOrderIterator& operator++() {
        if (m_currentIndex == -1) return *this;
        m_currentIndex++;
        if (m_currentIndex == m_size) m_currentIndex = -1; // End reached
        return *this;
    }
    reference operator*() const { return m_data[indices[m_currentIndex]]; }
    bool operator!=(const RandomOrderIterator& other) const { return m_currentIndex != other.m_currentIndex; }
    auto begin () const { return *this; }
    auto end () const { return RandomOrderIterator(m_data, m_size, true); }

private:
    pointer m_data;
    size_t m_size;
    int m_currentIndex;
    std::vector<size_t> indices;
};

template <typename T>
class Array {
  public:
    using pointer = T*;
    Array(pointer data, size_t size) : m_data(data), m_size(size) {}
    auto begin() const { return MyIterator<T>(m_data); }
    auto end() const { return MyIterator<T>(m_data + m_size); }
    auto randomIterable() const { return RandomOrderIterator<T>(m_data, m_size); }
  private:
    pointer m_data;
    size_t m_size;
};

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    Array<int> array(arr, 5);

    // Alternative is: for (auto& it : array)
    std::cout << "Sequential order:" << std::endl;
    for (auto it = array.begin(); it != array.end(); ++it) std::cout << *it << " ";

    std::cout << "\nRandom order:" << std::endl;
    for (auto &v : array.randomIterable()) std::cout << v << " ";
    std::cout << std::endl;
}
