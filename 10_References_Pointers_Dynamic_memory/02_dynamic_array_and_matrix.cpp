#include<iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }

    cout << sum << endl;

    cout << "Enter rows and cols:" << endl;
    int rows, cols;
    cin >> rows >> cols;

    int **matrix = new int *[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];

        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    int matrixSum = 0;
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            matrixSum += matrix[row][col];
        }
    }

    cout << matrixSum;

    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
}