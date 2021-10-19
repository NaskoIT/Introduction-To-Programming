#include <iostream>

using namespace std;

int main()
{
	int a, b, x;
	cin >> a >> b >> x;

	bool isInside = x > a && x < b;
	cout << isInside << endl;
}
