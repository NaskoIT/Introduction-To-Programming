#include <iostream>

using namespace std;

int main()
{
	char letter;
	cin >> letter;

	int letterAsciiCode = (int)letter;
	int uppercaseAAsciiCode = 'A';
	int number = letterAsciiCode - uppercaseAAsciiCode + 1;

	cout << number;
}
