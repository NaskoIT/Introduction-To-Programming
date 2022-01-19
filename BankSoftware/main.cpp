#include<iostream>
#include<string>
#include "global-constants.h"
#include "user-service.h"

using namespace std;

void renderGuestMenu() {
    cout << LOGIN_COMMAND << " - login" << endl;
    cout << REGISTER_COMMAND << " - register" << endl;
    cout << QUIT_COMMAND << " - quit" << endl;
}

void renderLoggedMenu() {
    cout << CANCEL_COMMAND << " - cancel account" << endl;
    cout << DEPOSIT_COMMAND << " - deposit" << endl;
    cout << LOGIN_COMMAND << " - logout" << endl;
    cout << TRANSFER_COMMAND << " - transfer" << endl;
    cout << WITHDRAW_COMMAND << " - withdraw" << endl;
}

int main() {
    loadUsers();

    string command = "";
    while (command != QUIT_COMMAND) {
        if (isLogged) {
            renderLoggedMenu();
        } else {
            renderGuestMenu();
        }

        cout << "Enter one of the following commands in the menu" << endl;
        cin >> command;

        if (command == LOGIN_COMMAND) {
            string username, password;
            cin >> username >> password;
            login(username, password);
            if (!isLogged) {
                cout << "Invalid username or password." << endl;
            }
        } else if (command == REGISTER_COMMAND) {
            string username, password;
            cin >> username >> password;
            cout << create(username, password);
        } else if (command == CANCEL_COMMAND) {
            cancelAccount();
        }
    }

    saveState();
}