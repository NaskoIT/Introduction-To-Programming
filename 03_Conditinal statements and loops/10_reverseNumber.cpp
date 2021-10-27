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

    int reversedNumber = 0;
    double multiplier = pow(10, digitsCount - 1);

    while (number > 0) {
        int digit = number % 10;
        reversedNumber += multiplier * digit;
        multiplier /= 10;
        number /= 10;
    }

    cout << reversedNumber;
}