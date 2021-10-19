#include <iostream>

using namespace std;

int main()
{
	// Apples: 2 0.6
	string name;
	cin >> name;

	int quantity;
	cin >> quantity;

	double price;
	cin >> price;

	cout << name << " " << price * quantity;
}