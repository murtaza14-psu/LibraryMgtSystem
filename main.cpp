#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class LibraryManagementSystem {
private:
    struct Node {
        int id;
        string author, title, publisher;
        Node *next_add;
    };
public:
    Node *head = NULL;
    void menu();
    void insert();
};

void header() {
    cout << "\n\n\t\t====================LIBRARY MANAGEMENT SYSTEM====================\n";
    cout << "\n\n\t\t1. Insert New Record";
    cout << "\n\n\t\t2. Search Record";
    cout << "\n\n\t\t3. Update Record";
    cout << "\n\n\t\t4. Delete Record";
    cout << "\n\n\t\t5. Show all Record";
    cout << "\n\n\t\t6. Exit";
    cout << "\n\n\t\tEnter Your Choice: ";
}

void LibraryManagementSystem::menu() {
    label1:
        system("cls");  // Clear the screen for Windows
        header();  // Show menu options

        int choice;
        cin >> choice;  // Get user's choice

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                head = NULL;
                // loadData();
                // searchRecord();
                break;

            case 3:
                head = NULL;
                // loadData();
                // updateRecord();
                break;

            case 4:
                head = NULL;
                // loadData();
                // delRecord();
                break;

            case 5:
                // sort();
                // head = NULL;
                // loadData();
                // showRecord();
                break;
            
            case 6:
                exit(0);  // Exit the program

            default:
                cout << "\n\nInvalid choice! Please Try Again";            
        }

        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get();  // Wait for a keypress before clearing the screen
        goto label1;  // Go back to the menu
}

void LibraryManagementSystem::insert() {
    // Insertion logic here
}

int main() {
    LibraryManagementSystem library;
    library.menu();  // Start the menu loop
}
