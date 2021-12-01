#include <iostream>

using namespace std;

const int ROWS = 3;
const int COLS = 4;

int main()
{
	int arr[ROWS][COLS];
	
	int counter = 1;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = counter;
			counter++;
		}
	}

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << " ";
		}

		cout << endl;
	}
}
