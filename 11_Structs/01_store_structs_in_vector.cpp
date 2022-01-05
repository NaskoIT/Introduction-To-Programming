#include<iostream>
#include <string>
#include <vector>

using namespace std;

struct User {
    string username;
    int age;
    string password;
};

int main() {
    // username password age
    int n;
    cin >> n;

    vector<User> users;
    for (int i = 0; i < n; ++i) {
        User user;
        cin >> user.username >> user.password >> user.age;
        users.push_back(user);
    }

    // other logic

    for (auto &user : users) {
        cout << user.username << " " << user.password << " " << user.age;
    }
}