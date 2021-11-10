#include <iostream>

using namespace std;

const int MAX_NUMBERS = 50;

void readArray(int arr[MAX_NUMBERS], int n);

int main() {
    int n;
    cin >> n;
    int numbers[MAX_NUMBERS];

    readArray(numbers, n);

    int max = INT32_MIN;
    int maxElementIndex = -1;
    for (int i = 0; i < n; ++i) {
        int current = numbers[i];

        if (max < current) {
            max = current;
            maxElementIndex = i;
        }
    }

    cout << "Max: " << max << " on index: " << maxElementIndex;
}

void readArray(int arr[MAX_NUMBERS], int n) {
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
};