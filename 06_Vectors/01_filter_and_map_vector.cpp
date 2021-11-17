#include <iostream>
#include <vector>

using namespace std;

vector<int> filter(vector<int> &collection, bool (*predicate)(int)) {
    vector<int> result;

    for (int item : collection) {
        if (predicate(item)) {
            result.push_back(item);
        }
    }

    return result;
}

bool isEven(int number) {
    return number % 2 == 0;
}

bool isNegative(int number) {
    return number < 0;
}

void printVector(vector<int> &collection) {
    for (int i = 0; i < collection.size(); ++i) {
        cout << collection[i] << " ";
    }

    cout << endl;
}

vector<int> map(vector<int> &collection, int (*func)(int)) {
    vector<int> mappedNumbers(collection.size());

    for (int i = 0; i < collection.size(); ++i) {
        mappedNumbers[i] = func(collection[i]);
    }

    return mappedNumbers;
}

int increase(int number) {
    return number + 1;
}

int multiplyByTwo(int number) {
    return number * 2;
}

int main() {
    vector<int> numbers = {-1, 1, -2, 2, 3, 4, 5, 6};

    vector<int> evenNumbers = filter(numbers, isEven);
    cout << "Print the even numbers" << endl;
    printVector(evenNumbers);

    cout << "Print negative numbers" << endl;
    vector<int> negativeNumbers = filter(numbers, isNegative);
    printVector(negativeNumbers);

    cout << "Print the increased numbers;" << endl;
    vector<int> increasedNumbers = map(numbers, increase);
    printVector(increasedNumbers);

    cout << "Print the numbers multiplied by two" << endl;
    vector<int> multipliedByTwoNumbers = map(numbers, multiplyByTwo);
    printVector(multipliedByTwoNumbers);
}