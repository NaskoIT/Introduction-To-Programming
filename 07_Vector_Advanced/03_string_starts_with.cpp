#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    char letter;
    cin >> letter;

    vector<string> strings;
    for (int i = 0; i < n; ++i) {
        string a;
        cin >> a;
        strings.push_back(a);
    }

    for (int i = 0; i < strings.size(); ++i) {
        string current = strings[i];
        if (current.length() > 0 && current[0] == letter) {
            cout << current;
        }
    }
}
