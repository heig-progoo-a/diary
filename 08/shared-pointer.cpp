#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

struct Book {
    string title, author;
    Book(const string &t, const string &a) : title{t}, author{a} {
        cout << "Book created " << '"' << title << "\" by " << author << endl;
    }
    ~Book() { cout << "Book destroyed " << '"' << title << "\" by " << author << endl; }
};

struct User {
    using BookPtr = shared_ptr<Book>;
    vector<BookPtr> checkedOutBooks;
    void checkout(const BookPtr &book) { checkedOutBooks.push_back(book); }
};

struct Library {
    vector<shared_ptr<Book>> books;
    shared_ptr<Book> addBook(const string &title, const string &author) {
        auto newBook = make_shared<Book>(title, author);
        books.push_back(newBook);
        return newBook;
    }
};

int main() {
    Library library;
    {
        auto book = library.addBook("The Art of Computer Programming", "Donald Knuth");
        cout << "Book's references? " << book.use_count() << endl;
        User alice;
        alice.checkout(book);
        {
            User bob;
            bob.checkout(book);
            cout << "Book's references? " << book.use_count() << endl;
        }
        cout << "Book's references? " << book.use_count() << endl;
    }
    cout << "Book's references? " << library.books.front().use_count() << endl;
}