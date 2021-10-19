#include <iostream>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;

	int sum = a + b;
	// int result = sum * sum * sum;
	int result = pow(sum, 3);

	cout << result;
}
