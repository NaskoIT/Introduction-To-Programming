#include <iostream>

using namespace std;

const int MAX_NUMBERS = 50;

void readArray(int arr[MAX_NUMBERS], int n);

int main() {
    int n;
    cin >> n;
    int numbers[MAX_NUMBERS];

    readArray(numbers, n);

    int min = INT32_MAX;
    int max = INT32_MIN;

    for (int i = 0; i < n; ++i) {
        int current = numbers[i];

        if (max < current) {
            max = current;
        }
        if (min > current) {
            min = current;
        }
    }

    cout << "Min: " << min << ", max: " << max;
}

void readArray(int arr[MAX_NUMBERS], int n) {
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
};