#ifndef ENCODINGPASSWORD_SOLUTIONS_H
#define ENCODINGPASSWORD_SOLUTIONS_H

// task 1 solution
void ConvertArr(long arr[], int startIndex, int endIndex) {
    if (startIndex >= endIndex) {
        return;
    }

    int counter = 0;
    int subArrayLength = endIndex - startIndex + 1;

    for (int i = startIndex; i < (subArrayLength / 2) + startIndex; ++i) {
        int sourceIndex = i;
        int destinationIndex = endIndex - counter;

        int temp = arr[sourceIndex];
        arr[sourceIndex] = arr[destinationIndex];
        arr[destinationIndex] = temp;

        counter++;
    }
}

// task 2 solution
int findElement(long arr[], int length) {
    for (int i = length - 2; i > 0; i--) {
        double currentAverage = (arr[i + 1] + arr[i - 1]) / 2.0;
        if (arr[i] > currentAverage) {
            return i;
        }
    }

    return -1;
}

const int MERGED_TABLE_ROWS = 2;

// task 3
int **mergeArrays(int *firstArr, int *secondArr, int length) {
    int **mergeTable = new int *[MERGED_TABLE_ROWS];

    for (int i = 0; i < MERGED_TABLE_ROWS; ++i) {
        mergeTable[i] = new int[length];

        for (int j = 0; j < length; ++j) {
            if (i == 0) {
                mergeTable[i][j] = firstArr[j];
            } else if (i == 1) {
                mergeTable[i][j] = secondArr[j];
            }
        }
    }

    return mergeTable;
}

#endif //ENCODINGPASSWORD_SOLUTIONS_H
