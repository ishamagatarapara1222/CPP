#include <iostream>
#include <string>
using namespace std;

int main() {
    int choice;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Division\n";
        cout << "2. Voting Eligibility\n";
        cout << "3. Password Validation\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        try {
            switch(choice) {
                case 1: {
                    int a, b;
                    cout << "Enter two numbers: ";
                    cin >> a >> b;

                    if(b == 0)
                        throw "Error: Cannot divide by zero!";

                    cout << "Result = " << a / b << endl;
                    break;
                }

                case 2: {
                    int age;
                    cout << "Enter age: ";
                    cin >> age;

                    if(age < 18)
                        throw age;

                    cout << "You are eligible to vote." << endl;
                    break;
                }

                case 3: {
                    string password;
                    cout << "Enter password: ";
                    cin >> password;

                    bool hasUpper = false;

                    for(int i = 0; i < password.length(); i++) {
                        if(isupper(password[i])) {
                            hasUpper = true;
                            break;
                        }
                    }

                    if(!hasUpper)
                        throw password;

                    cout << "Password is valid." << endl;
                    break;
                }

                case 4:
                    cout << "Exiting...\n";
                    break;

                default:
                    cout << "Invalid choice!\n";
            }
        }

        // Catch blocks
        catch(const char* msg) {
            cout << msg << endl;
        }

        catch(int age) {
            cout << "Error: Age " << age << " is less than 18. Cannot vote.\n";
        }

        catch(string pwd) {
            cout << "Error: Password must contain at least one uppercase letter.\n";
        }

    } while(choice != 4);

    return 0;
}