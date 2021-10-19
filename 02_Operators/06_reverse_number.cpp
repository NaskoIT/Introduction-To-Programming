#include <iostream>

using namespace std;

int main()
{
	int number;
	cin >> number;

	int lastDigit = number % 10;
	int thirdDigiti = (number / 10) % 10;
	int secondDigit = (number / 100) % 10;
	int firstDigit = number / 1000;

	int newNumber = lastDigit * 1000 + thirdDigiti * 100 + secondDigit * 10 + firstDigit;
	cout << newNumber;
}