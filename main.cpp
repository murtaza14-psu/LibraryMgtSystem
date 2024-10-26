#include <iostream>
#include <unordered_map>
#include <string>
#include<ctime>

using namespace std;

class LibraryManagementSystem {
private:
    struct Node {
        int id;
        string author, title, publisher;
        Node *next_add;
    };

    unordered_map<int, pair<string, time_t>> issuedBooks;  // Maps book ID to customer ID and return date
    Node *head = NULL;
    int nextBookId = 1;  // Tracks the next unique book ID

public:
    void menu();
    void insert();
    void search();
    void update();
    void deleteBook();
    void sortBooks();
    void showBooks();
    void issueBook();
    void showIssuedBooks();  // Function to display issued books

};
void header() {
    cout << "\n\n\t\t====================LIBRARY MANAGEMENT SYSTEM====================\n";
   
}


void LibraryManagementSystem::issueBook() {
    header();
    if (head == NULL) {
        cout << "\n\nNo records found!";
        return;
    }

    int bookId;
    string customerId;
    int days;
    cout << "Enter Book ID to issue: ";
    cin >> bookId;
    cout << "Enter Customer ID: ";
    cin >> customerId;
    cout << "Enter Time Limit (in days): ";
    cin >> days;

    Node *ptr = head, *prev = NULL;
    while (ptr != NULL) {
        if (ptr->id == bookId) {
            // Book found
            cout << "Issuing book:" << endl;
            cout << "Book ID: " << ptr->id << endl;
            cout << "Author: " << ptr->author << endl;
            cout << "Title: " << ptr->title << endl;
            cout << "Publisher: " << ptr->publisher << endl;

            // Calculate return date
            time_t now = time(0);
            time_t returnDate = now + days * 86400; // 86400 seconds per day

            // Add to issuedBooks map
            issuedBooks[bookId] = {customerId, returnDate};

            // Delete book from library
            if (ptr == head) {
                head = head->next_add;
            } else {
                prev->next_add = ptr->next_add;
            }
            delete ptr;

            cout << "Book issued successfully!\n";
            return;
        }
        prev = ptr;
        ptr = ptr->next_add;
    }

    cout << "Book with ID " << bookId << " not found!" << endl;
}

void LibraryManagementSystem::showIssuedBooks() {
    header();
    if (issuedBooks.empty()) {
        cout << "\n\nNo books have been issued.";
        return;
    }

    cout << "Issued Books:\n";
    for (const auto& issuedBook : issuedBooks) {
        int bookId = issuedBook.first;
        string customerId = issuedBook.second.first;
        time_t returnDate = issuedBook.second.second;

        // Convert return date to readable format
        char returnDateStr[20];
        strftime(returnDateStr, sizeof(returnDateStr), "%Y-%m-%d", localtime(&returnDate));

        cout << "Book ID: " << bookId << endl;
        cout << "Customer ID: " << customerId << endl;
        cout << "Return Date: " << returnDateStr << endl;
        cout << "------------------------------------------" << endl;
    }
}

void LibraryManagementSystem::menu() {
    label1:
        system("cls");  // Clear the screen for Windows
        header();  // Show menu options

         cout << "\n\n\t\t1. Insert New Record";
        cout << "\n\n\t\t2. Search Record";
        cout << "\n\n\t\t3. Update Record";
        cout << "\n\n\t\t4. Delete Record";
        cout << "\n\n\t\t5. Issue Book";
        cout << "\n\n\t\t6. Show all Record";
        cout << "\n\n\t\t7. Show issued Books";
        cout << "\n\n\t\t8. Exit";
        cout << "\n\n\t\tEnter Your Choice: ";

        int choice;
        cin >> choice;  // Get user's choice

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                // head = NULL;
                // loadData();
                search();
                break;

            case 3:
                // head = NULL;
                // loadData();
                update();
                break;

            case 4:
                // head = NULL;
                // loadData();
                deleteBook();
                break;

            case 5:
                issueBook();
                break;
            
            case 6:
                sortBooks();
                // head = NULL;
                // loadData();
                showBooks();
                break;
            case 7:
               showIssuedBooks();
               break;
            case 8:
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
    header();
    Node *newNode = new Node;
    
    newNode->id = nextBookId++;  // Set unique ID and increment for next book
    cout << "Assigned Book ID: " << newNode->id << endl;

    cout << "Author: ";
    cin >> newNode->author;
    cout << "Title: ";
    cin >> newNode->title;
    cout << "Publisher: ";
    cin >> newNode->publisher;
    newNode->next_add = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node *ptr = head;
        while (ptr->next_add != NULL) {
            ptr = ptr->next_add;
        }
        ptr->next_add = newNode;
    }
    cout << "\n\n\t\t\tNew Book inserted successfully!";
}
void LibraryManagementSystem::search() {

    header();
    if (head == NULL) {
        cout << "\n\nNo records found!";
        return;
    }

    int searchId;
    cout << "Enter Book ID to search: ";
    cin >> searchId;

    Node* ptr = head;
    while (ptr != NULL) {
        if (ptr->id == searchId) {
            cout << "Book found!" << endl;
            cout << "Book ID: " << ptr->id << endl;
            cout << "Author: " << ptr->author << endl;
            cout << "Title: " << ptr->title << endl;
            cout << "Publisher: " << ptr->publisher << endl;
            return;  // Exit once the book is found
        }
        ptr = ptr->next_add;  // Move to the next node
    }

    // If we reach here, the book was not found
    cout << "Book with ID " << searchId << " not found!" << endl;
}
void LibraryManagementSystem::update() {
    header();
    if (head == NULL) {
        cout << "\n\nNo records found!";
        return;
    }

    int searchId;
    cout << "Enter Book ID to search: ";
    cin >> searchId;

    Node* ptr = head;
    while (ptr != NULL) {
        if (ptr->id == searchId) {
            cout << "Book found!" << endl;
            cout << "Current details:" << endl;
            cout << "Book ID: " << ptr->id << endl;
            cout << "Author: " << ptr->author << endl;
            cout << "Title: " << ptr->title << endl;
            cout << "Publisher: " << ptr->publisher << endl;

            cout << "Enter new Book ID: ";
            cin >> ptr->id;
            cout << "Enter new Author: ";
            cin >> ptr->author;
            cout << "Enter new Title: ";
            cin >> ptr->title;
            cout << "Enter new Publisher: ";
            cin >> ptr->publisher;

            cout << "\t\t\t Book updated successfully" << endl;
            return;  // Exit once the book is found
        }
        ptr = ptr->next_add;  // Move to the next node
    }

    // If we reach here, the book was not found
    cout << "Book with ID " << searchId << " not found!" << endl;
}


void LibraryManagementSystem::deleteBook() {
    header();
    if (head == NULL) {
        cout << "\n\nNo records found!";
        return;
    }

    int deleteId;
    cout << "Enter Book ID to delete: ";
    cin >> deleteId;

    Node* ptr = head;
    Node* prev = NULL;

    // Traverse the list to find the book to delete
    while (ptr != NULL && ptr->id != deleteId) {
        prev = ptr;           // Keep track of the previous node
        ptr = ptr->next_add; // Move to the next node
    }

    // If the book was not found
    if (ptr == NULL) {
        cout << "Book with ID " << deleteId << " not found!" << endl;
        return;
    }

    // If the book to delete is the head
    if (ptr == head) {
        head = head->next_add; // Move head to the next node
    } else {
        // Unlink the node from the list
        prev->next_add = ptr->next_add; // Link previous node to the next node
    }

    delete ptr; // Free the memory of the deleted node
    cout << "Book with ID " << deleteId << " deleted successfully!" << endl;
}

void LibraryManagementSystem :: sortBooks(){
    if(head == NULL){
        cout<<"\n\n No records found"<<endl;
        cout << "Press Esc to return to menu...";
        cin.ignore();
        cin.get();  // Wait for a keypress before clearing the screen
        menu();
    }
    int count = 0, tempId;
    string tempTitle, tempAuthor, tempPublisher;
    Node *ptr = head;
    while(ptr != NULL){
        count ++;
        ptr = ptr->next_add;
    }
    for (int i = 1; i<=count; i++){
        Node *ptr = head;
        for (int j = 1; j< count ; j++){
            if( ptr -> id > ptr ->next_add->id ){
                //swap
                tempId=ptr->id;
                tempTitle= ptr->title;
                tempAuthor = ptr->author;
                tempPublisher = ptr ->publisher;

                ptr->id = ptr->next_add->id;
                ptr->title = ptr->next_add->title;
                ptr->author = ptr->next_add->author;
                ptr->publisher = ptr->next_add->publisher;

                ptr->next_add->id = tempId;
                ptr->next_add->title = tempTitle;
                ptr->next_add->author = tempAuthor;
                ptr->next_add->publisher = tempPublisher;
            }
            ptr = ptr->next_add;
        }
    }
}
void LibraryManagementSystem::showBooks(){


    Node* ptr = head;
    while (ptr != NULL) {
       
        cout << "Book ID: " << ptr->id << endl;
        cout << "Author: " << ptr->author << endl;
        cout << "Title: " << ptr->title << endl;
        cout << "Publisher: " << ptr->publisher << endl;
        cout <<"\n\n--------------------------------------------------\n\n";   
        ptr = ptr->next_add;  // Move to the next node
    }

}

int main() {
    LibraryManagementSystem library;
    library.menu();  // Start the menu loop
}
