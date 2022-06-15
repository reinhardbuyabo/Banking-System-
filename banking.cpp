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
    adminFile.close();
    if (adminName == name && adminPass == password) {
        return true;
    } else {
        return false;
    }
}

void registerClient(string name, string password) {
    ofstream usersDBFile;
    usersDBFile.open("usersDB.txt", ios::app);
    usersDBFile << name << endl << password << endl;

    fstream user(name + ".txt", ios::app);
    float account = 0;
    user << account;
    user.close();
}

bool login(string name, string password){
    bool abc = false;
    int count = 0;
    int temp;
    string userInfo;
    ifstream users;
    users.open("usersDB.txt");
    
    while (getline(users, userInfo)) {
        count++;
        if (userInfo == name) {
            temp = count;
            continue;
            }

        if (temp == (count - 1)) {
            if (password == userInfo) {
                abc = true;
                users.close();
                break;
            }
        }
    }
    return abc;
}

void deposit(string name, float deposit) {
   ifstream client(name + ".txt");
   float balance;
   
   client >> balance;
   balance += deposit;
   client.close();

   ofstream user(name + ".txt");
   user << balance;
   user.close();
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
            if (optiontwo == 1) {
                // Implementation of withdrawing.
                // withdraw();
            }

        } else {
            cout << "Wrong credentials!" << endl;
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
        string clientName;
            if(optionthree == 1){
                // Implementation for depositing money for client.
                cout << "Enter client name: ";
                cin >> clientName;
                cout << "Enter amount to deposit: ";
                float amount;
                cin >> amount;
                deposit(clientName, amount);
                return 0;
            } else if (optionthree == 2) {
                cout << "Enter client name: ";
                cin >> clientName;
                cout << "Enter client password: ";
                string clientPassword;
                cin >> clientPassword;
                registerClient(clientName, clientPassword);
            }
        } else {
            cout << "Wrong username or password!" << endl;
        }
    }
}