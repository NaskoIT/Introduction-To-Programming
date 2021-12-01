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

// abcabcdba
// a -> 3
// b -> 3
// c -> 2
// d -> 1
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
    
    bool visited[ASCII_TABLE_LENGTH] = { false };

    for (int i = 0; i < length; i++)
    {
        char symbol = word[i];
        int index = (int)symbol;
        if(!visited[index]) {
            visited[index] = true;
            cout << symbol << " -> " << occurrances[index];
        }
    }
}
