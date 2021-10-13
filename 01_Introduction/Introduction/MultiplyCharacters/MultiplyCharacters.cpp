#include <iostream>

using namespace std;

int main()
{
    char firstChar, secondChar;
    cin >> firstChar >> secondChar;

    int firstCharAsDigit = firstChar - '0';
    int secondCharAsDigit = secondChar - '0';

    cout << firstCharAsDigit * secondCharAsDigit;
}