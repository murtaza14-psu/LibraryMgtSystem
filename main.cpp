#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

struct Book {
    string title;
    string author;
    int year;

    // Default constructor
    Book() : title("Untitled"), author("1Unknown"), year(0) {}

    // Parameterized constructor for initializing with values
    Book(string t, string a, int y) : title(t), author(a), year(y) {}

    // Display method to show book details
    void display() const {
        cout << "Title: " << title << ", Author: " << author << ", Year: " << year << endl;
    }
};

int main() {
    unordered_map<string, Book> library;

    // Adding a book to the library
    library["1984"] = Book("1984", "George Orwell", 1949);

    // Display the book details
    library["1984"].display();

    return 0;
}
