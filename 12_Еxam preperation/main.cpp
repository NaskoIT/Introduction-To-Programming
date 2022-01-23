#include <iostream>
#include "solutions.h"

using namespace std;

const char TERMINATING_SYMBOL = '\0';

void testConvertArr() {
    long input[] = {4, 5, 6, 7, 8, 9, 0, 1};
    ConvertArr(input, 2, 7);

    for (auto value : input) {
        cout << value << " ";
    }
}

void testFindElement() {
    long arr[] = {1, 2, 3, 4, 5};
    cout << findElement(arr, 6);
}

void printArr(int *arr, int length) {
    for (int i = 0; i < length; ++i) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

void testMergeArrays() {
    int length = 5;
    // 0 1 2 3 4
    int *firstArr = new int[length];
    // 1 3 5 7 9
    int *secondArr = new int[length];
    for (int i = 0; i < length; ++i) {
        firstArr[i] = i;
        secondArr[i] = i * 2 + 1;
    }

    int **matrix = mergeArrays(firstArr, secondArr, length);

    printArr(firstArr, length);
    printArr(secondArr, length);

    for (int i = 0; i < MERGED_TABLE_ROWS; ++i) {
        int *currentRow = matrix[i];
        printArr(currentRow, length);
    }

    for (int i = 0; i < MERGED_TABLE_ROWS; ++i) {
        delete[] matrix[i];
    }

    delete[] matrix;
}

int main() {
    // testConvertArr();
    // testFindElement();
    testMergeArrays();
}