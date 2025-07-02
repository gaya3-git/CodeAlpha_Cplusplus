#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
using namespace std;

// Function to validate username and password
bool validateUsernamePassword(const string& username, const string& password) {
    if (username.empty() || password.empty()) {
        cout << "Username or password cannot be empty!" << endl;
        return false;
    }
    if (username.find(' ') != string::npos || password.find(' ') != string::npos) {
        cout << "Username or password cannot contain spaces!" << endl;
        return false;
    }
    return true;
}

// Check if a user already exists
bool userExists(const string& username) {
    string filename = username + ".txt";
    return filesystem::exists(filename);
}

// Register a new user
void registerUser() {
    string username, password;
    cout << "Enter a new username: ";
    cin >> username;
    cout << "Enter a new password: ";
    cin >> password;

    if (!validateUsernamePassword(username, password))
        return;

    if (userExists(username)) {
        cout << "Username already exists! Try another one.\n";
        return;
    }

    ofstream file(username + ".txt");
    file << username << endl << password << endl;
    file.close();

    cout << "Registration successful!\n";
}

// Login function
void loginUser() {
    string username, password;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    if (!validateUsernamePassword(username, password))
        return;

    if (!userExists(username)) {
        cout << "User not found. Please register first.\n";
        return;
    }

    ifstream file(username + ".txt");
    string storedUsername, storedPassword;
    getline(file, storedUsername);
    getline(file, storedPassword);
    file.close();

    if (username == storedUsername && password == storedPassword) {
        cout << "Login successful! Welcome back, " << username << "!\n";
    } else {
        cout << "Incorrect username or password.\n";
    }
}

// Main menu
int main() {
    int choice;
    while (true) {
        cout << "\n--- Login and Registration System ---\n";
        cout << "1. Register\n2. Login\n3. Exit\nChoose option: ";
        cin >> choice;

        if (choice == 1)
            registerUser();
        else if (choice == 2)
            loginUser();
        else if (choice == 3) {
            cout << "Goodbye!\n";
            break;
        }
        else
            cout << "Invalid choice. Try again.\n";
    }

    return 0;
}
