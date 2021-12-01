#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const char TERMINATE_SYMBOL = '\0';
const int ASCII_TABLE_LENGTH = 128;

int getLength(char* word) {
	int index = 0;
	while (word[index] != TERMINATE_SYMBOL) {
		index++;
	};

	return index;
}

int main()
{
	char word[100];
	cin >> word;

	int length = getLength(word);
	int occurrances[ASCII_TABLE_LENGTH] = { 0 };

	for (int i = 0; i < length; i++)
	{
		char symbol = word[i];
		int index = (int)symbol;
		occurrances[index]++;
	}

	for (int i = 0; i < ASCII_TABLE_LENGTH; i++)
	{
		if (occurrances[i] != 0) {
			cout << (char)i << " -> " << occurrances[i] << endl;
		}
	}
}
