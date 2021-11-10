#include <iostream>

using namespace std;

const int MAX_NUMBERS = 50;

void readArray(int arr[MAX_NUMBERS], int n);

int main() {
    int n;
    cin >> n;
    int firstSequence[MAX_NUMBERS];
    int secondSequence[MAX_NUMBERS];

    readArray(firstSequence, n);
    readArray(secondSequence, n);

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += firstSequence[i] * secondSequence[i];
    }

    cout << sum;
}

void readArray(int arr[MAX_NUMBERS], int n) {
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
}