#include <iostream>
#include <string>
using namespace std;

#define MAX_ITEMS 100

// ================= ABSTRACT BASE CLASS =================
class LibraryItem {
private:
    string title;
    string author;
    string dueDate;

public:
    // Constructor
    LibraryItem(string t, string a, string d)
        : title(t), author(a), dueDate(d) {}

    // Getters
    string getTitle() { return title; }
    string getAuthor() { return author; }
    string getDueDate() { return dueDate; }

    // Setters
    void setTitle(string t) { title = t; }
    void setAuthor(string a) { author = a; }
    void setDueDate(string d) { dueDate = d; }

    // Pure Virtual Functions
    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() = 0;

    // Virtual Destructor
    virtual ~LibraryItem() {}
};

// ================= DERIVED CLASS: BOOK =================
class Book : public LibraryItem {
private:
    int pages;

public:
    Book(string t, string a, string d, int p)
        : LibraryItem(t, a, d), pages(p) {}

    void checkOut() override {
        cout << "Book checked out successfully.\n";
    }

    void returnItem() override {
        cout << "Book returned successfully.\n";
    }

    void displayDetails() override {
        cout << "\n--- Book Details ---\n";
        cout << "Title: " << getTitle() << endl;
        cout << "Author: " << getAuthor() << endl;
        cout << "Due Date: " << getDueDate() << endl;
        cout << "Pages: " << pages << endl;
    }
};

// ================= DERIVED CLASS: DVD =================
class DVD : public LibraryItem {
private:
    int duration;

public:
    DVD(string t, string a, string d, int dur)
        : LibraryItem(t, a, d), duration(dur) {}

    void checkOut() override {
        cout << "DVD checked out successfully.\n";
    }

    void returnItem() override {
        cout << "DVD returned successfully.\n";
    }

    void displayDetails() override {
        cout << "\n--- DVD Details ---\n";
        cout << "Title: " << getTitle() << endl;
        cout << "Author: " << getAuthor() << endl;
        cout << "Due Date: " << getDueDate() << endl;
        cout << "Duration: " << duration << " mins\n";
    }
};

// ================= DERIVED CLASS: MAGAZINE =================
class Magazine : public LibraryItem {
private:
    int issueNumber;

public:
    Magazine(string t, string a, string d, int issue)
        : LibraryItem(t, a, d), issueNumber(issue) {}

    void checkOut() override {
        cout << "Magazine checked out successfully.\n";
    }

    void returnItem() override {
        cout << "Magazine returned successfully.\n";
    }

    void displayDetails() override {
        cout << "\n--- Magazine Details ---\n";
        cout << "Title: " << getTitle() << endl;
        cout << "Author: " << getAuthor() << endl;
        cout << "Due Date: " << getDueDate() << endl;
        cout << "Issue Number: " << issueNumber << endl;
    }
};

// ================= MAIN FUNCTION =================
int main() {
    LibraryItem* items[MAX_ITEMS];
    int count = 0;

    int choice;

    do {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. Add DVD\n";
        cout << "3. Add Magazine\n";
        cout << "4. Display All Items\n";
        cout << "5. Checkout Item\n";
        cout << "6. Return Item\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        try {
            if (choice < 1 || choice > 7)
                throw invalid_argument("Invalid menu choice!");

            if (choice == 1) {
                string title, author, dueDate;
                int pages;

                cout << "Enter Title: ";
                cin.ignore();
                getline(cin, title);

                cout << "Enter Author: ";
                getline(cin, author);

                cout << "Enter Due Date: ";
                getline(cin, dueDate);

                cout << "Enter Pages: ";
                cin >> pages;

                if (pages < 0)
                    throw invalid_argument("Pages cannot be negative!");

                items[count++] = new Book(title, author, dueDate, pages);
            }

            else if (choice == 2) {
                string title, author, dueDate;
                int duration;

                cout << "Enter Title: ";
                cin.ignore();
                getline(cin, title);

                cout << "Enter Author: ";
                getline(cin, author);

                cout << "Enter Due Date: ";
                getline(cin, dueDate);

                cout << "Enter Duration (mins): ";
                cin >> duration;

                if (duration < 0)
                    throw invalid_argument("Duration cannot be negative!");

                items[count++] = new DVD(title, author, dueDate, duration);
            }

            else if (choice == 3) {
                string title, author, dueDate;
                int issue;

                cout << "Enter Title: ";
                cin.ignore();
                getline(cin, title);

                cout << "Enter Author: ";
                getline(cin, author);

                cout << "Enter Due Date: ";
                getline(cin, dueDate);

                cout << "Enter Issue Number: ";
                cin >> issue;

                if (issue < 0)
                    throw invalid_argument("Issue number cannot be negative!");

                items[count++] = new Magazine(title, author, dueDate, issue);
            }

            else if (choice == 4) {
                for (int i = 0; i < count; i++) {
                    items[i]->displayDetails();
                }
            }

            else if (choice == 5) {
                int index;
                cout << "Enter item index: ";
                cin >> index;

                if (index < 0 || index >= count)
                    throw out_of_range("Invalid index!");

                items[index]->checkOut();
            }

            else if (choice == 6) {
                int index;
                cout << "Enter item index: ";
                cin >> index;

                if (index < 0 || index >= count)
                    throw out_of_range("Invalid index!");

                items[index]->returnItem();
            }

        } catch (exception &e) {
            cout << "Error: " << e.what() << endl;
        }

    } while (choice != 7);


    for (int i = 0; i < count; i++) {
        delete items[i];
    }

    cout << "Program exited successfully.\n";
    return 0;
}