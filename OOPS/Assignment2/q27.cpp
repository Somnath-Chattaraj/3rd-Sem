#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Book {
private:
    string isbn;
    string title;
    vector<string> authors;
    double price;

public:
    Book(string isbn, string title, const vector<string>& authors, double price)
        : isbn(isbn), title(title), authors(authors), price(price) {}

    string getISBN() const {
        return isbn;
    }

    string getTitle() const {
        return title;
    }

    double getPrice() const {
        return price;
    }
};

class BookStore {
private:
    map<string, int> inventory;

public:
    void addBook(const Book& book, int quantity) {
        inventory[book.getISBN()] += quantity;
    }

    void sellBook(const string& isbn) {
        if (inventory[isbn] > 0) {
            --inventory[isbn];
        } else {
            cout << "Book out of stock!" << endl;
        }
    }

    void disp() const {
        for (const auto& pair : inventory) {
            cout << "ISBN: " << pair.first << " - Quantity: " << pair.second << endl;
        }
    }
};

int main() {
    BookStore store;

    Book book1("123456789", "C++ Primer", {"Stanley Lippman", "Josée Lajoie"}, 49.99);
    Book book2("987654321", "Effective C++", {"Scott Meyers"}, 39.99);

    store.addBook(book1, 10);
    store.addBook(book2, 5);

    store.disp();

    store.sellBook("123456789");

    store.disp();

    return 0;
}
