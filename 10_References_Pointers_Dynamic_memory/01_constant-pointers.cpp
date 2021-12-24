#include<iostream>

using namespace std;

int sum(const int* a, const int * b) {
    // Compile time error
    // *a = 100;
    return *a + *b;
}

int main() {
    cout << "Pointer to constants" << endl;

    const int a = 5;
    const int* b = &a;
    const int x = 60;
    // Compile time error
    // *b = 20;
    b = &x;
    cout << *b << endl;


    cout << "Constant pointers" << endl;
    int y = 50;
    int* const z = &y;
    int f = 50;
    // Compile time error
    // z = &f;
    *z = 100;
    cout << y;

    int e = 10;
    int g = 20;
    cout << endl << sum(&e, &g) << endl;
    cout << e;
}