#include <iostream>

using namespace std;

const int MAX_NUMBERS = 50;
const int NOT_FOUND = -1;

void readArray(int arr[MAX_NUMBERS], int n);

int indexOf(int array[MAX_NUMBERS], int n, int element);

int main() {
    int n;
    cin >> n;
    int numbers[MAX_NUMBERS];

    readArray(numbers, n);

    int element;
    cin >> element;

    int index = indexOf(numbers, n, element);

    cout << (index == NOT_FOUND ? "Not found!" : to_string(index));
}

void readArray(int arr[MAX_NUMBERS], int n) {
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
};

int indexOf(int array[MAX_NUMBERS], int n, int element) {
    // linear search
    for (int i = 0; i < n; ++i) {
        if(array[i] == element) {
            return i;
        }
    }

    return NOT_FOUND;
};