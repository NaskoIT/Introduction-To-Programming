#include <iostream>

using namespace std;

const int MAX_NUMBERS = 50;
const int NOT_FOUND = -1;

void readArray(int arr[MAX_NUMBERS], int n);

int indexOf(int array[MAX_NUMBERS], int n, int element);

bool binarySearch(int array[MAX_NUMBERS], int n, int element);

int main() {
    int n;
    cin >> n;
    int numbers[MAX_NUMBERS];

    readArray(numbers, n);

    int element;
    cin >> element;

    bool exists = binarySearch(numbers, n, element);

    cout << (exists ? "Element found" : "Not found!");
}

void readArray(int arr[MAX_NUMBERS], int n) {
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
};

int indexOf(int array[MAX_NUMBERS], int n, int element) {
    // linear search
    for (int i = 0; i < n; ++i) {
        if (array[i] == element) {
            return i;
        }
    }

    return NOT_FOUND;
};

bool binarySearch(int array[MAX_NUMBERS], int n, int element) {
    int startIndex = 0;
    int endIndex = n - 1;

    while (startIndex <= endIndex) {
        int middleIndex = (startIndex + endIndex) / 2;
        int currentElement = array[middleIndex];

        if (currentElement < element) {
            startIndex = middleIndex + 1;
        } else if (currentElement > element) {
            endIndex = middleIndex - 1;
        } else {
            return true;
        }
    }

    return false;
}