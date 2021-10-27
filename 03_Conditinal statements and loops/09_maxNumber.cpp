#include <iostream>
#include <limits.h>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int maxNumber = INT_MIN;

	for (int i = 0; i < n; i++)
	{
		int currentNumber;
		cin >> currentNumber;

		if (maxNumber < currentNumber) {
			maxNumber = currentNumber;
		}
	}

	cout << maxNumber;
}