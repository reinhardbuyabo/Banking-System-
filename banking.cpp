#include <iostream>
#include <string>
using namespace std; 

int main () {
    cout << "*****WELCOME TO E-CASH SERVICES*****" << endl;
    cout << "1. Normal User Login" << endl;
    cout << "2. Administrator Login" << endl << endl;
    cout << "Choose an option to proceed: ";
    int option;
    cin >> option;
    cout << endl << "--------------------------------------------------" << endl;

    if (option == 1) {
        cout << "Welcome to the Normal User Login Page:" << endl << endl;
        cout << "Enter Username: ";
        string username;
        cin >> username;
        cout << "Enter password: ";
        string password;
        cin >> password;
        cout << endl << "--------------------------------------------------" << endl;
        // Missing code for functionality that involves user login.
        
        cout << "Welcome " << username << endl;
        cout << "1. Withdraw cash" << endl;
        cout << "2. Check balance" << endl;
        cout << "3. Reset you password" << endl << endl;
        cout << "Enter your option to proceed: ";
        int optiontwo;
        cin >> optiontwo;
    } else if (option == 2) {
        cout << "Welcome to the Registration and Deposit page" << endl;
        cout << "Enter administrator username and password." << endl;
        cout << "Enter username: ";
        string adminUsername;
        cin >> adminUsername;
        cout << "Enter password: ";
        string adminPassword;
        cin >> adminPassword;
        cout << endl << "--------------------------------------------------" << endl;
        // Missing code for functionality that involves admin login.

        cout << "Welcome "<< adminUsername << endl;
        cout << "1. Deposit money for client" << endl;
        cout << "2. Register new client" << endl;
        cout << "3. Reset your password" << endl << endl;
        cout << endl << "--------------------------------------------------" << endl;
        cout << "Enter your option to proceed: ";
        int optionthree;
        cin >> optionthree;

    }
}