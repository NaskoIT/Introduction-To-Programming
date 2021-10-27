#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int number;
    cin >> number;

    int tempNumber = number;
    int digitsCount = 1;

    while (tempNumber >= 10) {
        tempNumber /= 10;
        digitsCount++;
    }

    int multiplier = 1;
    for (int i = 0; i < digitsCount - 1; ++i) {
        multiplier *= 10;
    }

    int position = digitsCount - 1;
    while (position >= 0) {
        if (position % 2 == 0) {
            int digit = (number / multiplier) % 10;
            cout << digit << " ";
        }

        multiplier /= 10;
        position--;
    }
}