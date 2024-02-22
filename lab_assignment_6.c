#include <stdio.h>
#include <stdlib.h>

int binarySearch(int numbers[], int low, int high, int value) {
    if (low <= high) {
        int mid = low + (high - low) / 2;

        if (numbers[mid] == value) {
            return mid;
        } else if (numbers[mid] < value) {
            return binarySearch(numbers, mid + 1, high, value);
        } else {
            return binarySearch(numbers, low, mid - 1, value);
        }
    }

    return -1; // Element not found
}

int search(int numbers[], int low, int high, int value) {
    return binarySearch(numbers, low, high, value);
}

void printArray(int numbers[], int sz) {
    int i;
    printf("Number array: ");
    for (i = 0; i < sz; ++i) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}

int main(void) {
    int i, numInputs;
    int value, index;
    int* numArray = NULL;
    int countOfNums;
    FILE* inFile = fopen("input.txt", "r");

    fscanf(inFile, " %d\n", &numInputs);

    while (numInputs-- > 0) {
        fscanf(inFile, " %d\n", &countOfNums);
        numArray = (int*)malloc(countOfNums * sizeof(int));

        for (i = 0; i < countOfNums; i++) {
            fscanf(inFile, " %d", &value);
            numArray[i] = value;
        }

        printArray(numArray, countOfNums);
        index = search(numArray, 0, countOfNums - 1, numArray[countOfNums / 2]);

        if (index >= 0) {
            printf("Item %d exists in the number array at index %d!\n", numArray[countOfNums / 2], index);
        } else {
            printf("Item %d does not exist in the number array!\n", numArray[countOfNums / 2]);
        }

        free(numArray);
    }

    fclose(inFile);

    return 0;
}
