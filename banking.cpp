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
    bool logged = false;
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
                logged = true;
                users.close();
                break;
            }
        }
    }
    return logged;
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

string withdraw(string name, float withdrawal) {
    ifstream bal(name + ".txt");
    float balance;
    bal >> balance;
    bal.close();
    ofstream customer(name + ".txt");
    if (balance > withdrawal) {
        balance -= withdrawal;
        customer << balance;
        customer.close();
        return "Successful.";
    } else {
        return "Failed! Not enough money on account.";
    }
}

float checkBalance(string name) {
    ifstream checkBal(name + ".txt");
    float balance;

    checkBal >> balance;
    return balance;
}

string userPasswordReset(string name, string oldpassword, string newpassword) {
    ifstream user("usersDB.txt");
    ofstream tempFile("tempfile.txt");

    int count = 0, temp;
    bool changed = false;
    
    string userInfo;
    while(getline(user, userInfo)) {
        count++;
        if (userInfo == name) {
            temp = count;
        }

        if (temp == (count - 1)) {
            if (oldpassword == userInfo) {
                userInfo = newpassword;
                changed = true;                
            }
        }
        userInfo += "\n";
        tempFile << userInfo;
    }
    user.close();
    tempFile.close();
    remove("usersDB.txt");
    rename("tempFile.txt", "usersDB.txt");
    if (changed) {
         return "Password changed successfully";
    } else {
        return "Failed!";
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
            if (optiontwo == 1) {
                cout << "How much do you want to withdraw: ";
                float cash;
                cin >> cash;
                cout << "Transaction " << withdraw(username, cash) << endl;
            } else if (optiontwo == 2) {
                cout << "Balance: " << checkBalance(username) << endl;
            } else if (optiontwo == 3) {
                cout << "Enter old password: ";
                string oldPassword;
                cin >> oldPassword;
                cout << "Enter new password: ";
                string newPassword;
                cin >> newPassword;
                cout << userPasswordReset(username, oldPassword, newPassword) << endl;
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