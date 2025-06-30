#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool registerUser(const string& username, const string& password) {
    ifstream infile("users.txt");
    string u, p;

    while (infile >> u >> p) {
        if (u == username) {
            cout << "Username already exists!\n";
            return false;
        }
    }
    infile.close();

    ofstream outfile("users.txt", ios::app);
    outfile << username << " " << password << endl;
    return true;
}

bool loginUser(const string& username, const string& password) {
    ifstream infile("users.txt");
    string u, p;

    while (infile >> u >> p) {
        if (u == username && p == password) {
            return true;
        }
    }

    return false;
}

int main() {
    int choice;
    string username, password;

    cout << "1. Register\n2. Login\nEnter choice: ";
    cin >> choice;

    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    if (choice == 1) {
        if (registerUser(username, password))
            cout << "Registration successful!\n";
    } else if (choice == 2) {
        if (loginUser(username, password))
            cout << "Login successful!\n";
        else
            cout << "Invalid credentials!\n";
    }

    return 0;
}