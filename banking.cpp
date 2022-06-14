#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool adminLogin(string name, string password){
    ifstream adminFile;
    adminFile.open(name + ".txt");
    string adminName;
    adminFile >> adminName;
    string adminPass;
    adminFile >> adminPass;

    if (adminName == name && adminPass == password) {
        return true;
    } else {
        return false;
    }
};

bool login(string name, string password){
    ifstream userFile;
    userFile.open(name + ".txt");
    string userName;
    userFile >> userName;
    string userPass;
    userFile >> userPass;

    if (userName == name && userPass == password) {
        return true;
    } else {
        return false;
    }
}

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
        if (login(username, password)) {
            cout << "Welcome " << username << endl;
        cout << "1. Withdraw cash" << endl;
        cout << "2. Check balance" << endl;
        cout << "3. Reset you password" << endl << endl;
        cout << "Enter your option to proceed: ";
        int optiontwo;
        cin >> optiontwo;
        } else {
            cout << "Ask admin to register you!";
        }
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
        if (adminLogin(adminUsername, adminPassword)) {
            cout << "Welcome "<< adminUsername << endl;
        cout << "1. Deposit money for client" << endl;
        cout << "2. Register new client" << endl;
        cout << "3. Reset your password" << endl;
        cout << endl << "--------------------------------------------------" << endl;
        cout << "Enter your option to proceed: ";
        int optionthree;
        cin >> optionthree;
        } else {
            cout << "Wrong password!" << endl;
        }
    }
}