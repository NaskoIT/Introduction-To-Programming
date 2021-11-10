#include <iostream>

using namespace std;

const int MAX_STUDENTS = 50;

int main() {
    int n;
    cin >> n;
    int grades[MAX_STUDENTS];

    for (int i = 0; i < n; ++i) {
        cin >> grades[i];
    }

    int gradesSum = 0;
    for (int i = 0; i < n; ++i) {
        gradesSum += grades[i];
    }

    double averageGrade = (double) gradesSum / n;
    cout << averageGrade;
}