#include <iostream>
#include <vector>
#include <map>

class Book {
private:
    std::string isbn;
    std::string title;
    std::vector<std::string> authors;
    double price;

public:
    Book(std::string isbn, std::string title, const std::vector<std::string>& authors, double price)
        : isbn(isbn), title(title), authors(authors), price(price) {}

    std::string getISBN() const {
        return isbn;
    }

    std::string getTitle() const {
        return title;
    }

    double getPrice() const {
        return price;
    }
};

class BookStore {
private:
    std::map<std::string, int> inventory;

public:
    void addBook(const Book& book, int quantity) {
        inventory[book.getISBN()] += quantity;
    }

    void sellBook(const std::string& isbn) {
        if (inventory[isbn] > 0) {
            --inventory[isbn];
        } else {
            std::cout << "Book out of stock!" << std::endl;
        }
    }

    void disp() const {
        for (const auto& pair : inventory) {
            std::cout << "ISBN: " << pair.first << " - Quantity: " << pair.second << std::endl;
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
