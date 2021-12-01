#include <iostream>
#include <vector>

using namespace std;

const int ROWS = 3;
const int COLS = 4;

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> matrix(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int element;
			cin >> element;
			matrix[i].push_back(element);
		}
	}

	int mainDiagonalSum = 0;
	for (int i = 0; i < matrix.size(); i++)
	{
		mainDiagonalSum += matrix[i][i];
	}

	int secondaryDiagonalSum = 0;
	for (int i = 0; i < matrix.size(); i++)
	{
		secondaryDiagonalSum += matrix[i][n - i - 1];
	}

	cout << "Main diagonal sum: " << mainDiagonalSum << endl;
	cout << "Secondary diagonal sum: " << secondaryDiagonalSum << endl;
}
