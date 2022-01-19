#ifndef ENCODINGPASSWORD_USER_SERVICE_H
#define ENCODINGPASSWORD_USER_SERVICE_H

#include <string>
#include <vector>
#include "user.h"
#include "global-constants.h"

using namespace std;

vector<User> users;
bool isLogged = false;
User loggedUser;

void loadUsers() {
    // TODO: load all the users from the file and add the to the users vector
}

bool validateUsername(string username) {
    // TODO: validate the username according to the requirements
    return true;
}

bool validatePassword(string password) {
    // TODO: validate the password according to the requirements
    return true;
}

string hashPassword(string password) {
    // TODO: has the password using SHA-512
    return password;
}

bool existsByUsername(string username) {
    for (User &user : users) {
        if (user.username == username) {
            return true;
        }
    }

    return false;
}

void login(string username, string password) {
    string hashedPassword = hashPassword(password);
    for (User &user : users) {
        if (user.username == username && user.password == hashedPassword) {
            isLogged = true;
            loggedUser = user;
        }
    }
}

string create(string username, string password) {
    if (!validateUsername(username)) {
        return "Invalid username.";
    }
    if (!validatePassword(password)) {
        return "Invalid password.";
    }
    if (existsByUsername(username)) {
        return "User with the same email already exists.";
    }

    User user = {username, hashPassword(password), 0};
    users.push_back(user);

    isLogged = true;
    loggedUser = user;
    return REGISTERED_SUCCESSFULLY_MESSAGE;
}

void logout() {
    loggedUser = {"", "", 0};
    isLogged = false;
}

void cancelAccount() {
    // TODO: delete the account
    logout();
}

void deposit(double amount) {
    loggedUser.balance += amount;
}

void transfer(string username, double amount) {
    // TODO: implement the function
}

void withdraw(double amount) {
}

void saveState() {
    // TODO: save the changed data in the file
}

#endif //ENCODINGPASSWORD_USER_SERVICE_H
