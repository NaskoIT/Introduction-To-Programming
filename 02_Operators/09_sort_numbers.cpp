#include <iostream>

using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;

	/*int minNumber = 0;
	int middleNumber = 0;
	int maxNumber = 0;


	if (a < b && a < c) {
		minNumber = a;
		if (b < c) {
			middleNumber = b;
			maxNumber = c;
		}
		else {
			middleNumber = c;
			maxNumber = b;
		}
	}
	else if (b < a && b < c) {
		minNumber = b;
		if (a < c) {
			middleNumber = a;
			maxNumber = c;
		}
		else {
			middleNumber = c;
			maxNumber = a;
		}
	}
	else {
		minNumber = c;
		if (a < b) {
			middleNumber = a;
			maxNumber = c;
		}
		else {
			middleNumber = c;
			maxNumber = a;
		}
	}*/


	int minNumber = min(min(a, b), c);
	int maxNumber = max(max(a, b), c);
	int middleNumber = 0;

	if (a >= b && a <= c) {
		middleNumber = a;
	}
	else if (b >= a && b <= c) {
		middleNumber = b;
	}
	else {
		middleNumber = c;
	}

	cout << minNumber << " " << middleNumber << " " << maxNumber << endl;
}