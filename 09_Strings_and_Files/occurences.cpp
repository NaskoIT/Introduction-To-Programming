#include<iostream>
#include<vector>

using namespace std;

const int MAX_LENGTH = 1024;
const int LETTERS_COUNT = 128;

int main() {
    char str[MAX_LENGTH];
    cin >> str;
    int occurrences[LETTERS_COUNT] = {};

    int index = 0;
    while (str[index] != '\0') {
        int charCode = (int) str[index];
        occurrences[charCode]++;
        index++;
    }

//    bool isUnique = true;
//    for (int i = 0; i < LETTERS_COUNT; ++i) {
//        if (occurrences[i] > 1) {
//            isUnique = false;
//            break;
//        }
//    }
//    cout << isUnique << endl;


    for (int i = 0; i < LETTERS_COUNT; ++i) {
        for (int j = 0; j < occurrences[i]; ++j) {
            cout << (char) i;
        }
    }

    cout << endl;

}