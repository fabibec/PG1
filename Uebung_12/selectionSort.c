#include <stdio.h>

void printArray(int array[], int length);
void selectionSort(int array[], int length);

int main (void) {
    // Example arrays to test the code
    int array1[] = {9,8,7,6,5,4,3,2,1, 0};
    int array2[] = {0,1,2,3,4,5,6,7,8,9};
    int array3[] = {5,7,8,9,4,6,4,2,1,5,7};
    int array4[] = {8,4,6,0,2,1,5};
    printArray(array1, 10);
    selectionSort(array1, 10);
    printArray(array1, 10);
    printArray(array2, 10);
    selectionSort(array2, 10);
    printArray(array2, 10);
    printArray(array3, 11);
    selectionSort(array3, 11);
    printArray(array3, 11);
    printArray(array4, 7);
    selectionSort(array4, 7);
    printArray(array4, 7);
    return 0;
}

/**
 * Function that print any given array to the terminal
 * @param array
 * @param length length of the given array
 */
void printArray(int array[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

/**
 * Sorts array using the selection sort algorithm form smallest to highest
 * @param array
 * @param length length of the given array
 */
void selectionSort(int array[], int length) {
    int min_val_pos;
    for (int i = 0; i < length - 1; i++) {
        // Set first unsorted value as smallest unsorted value
        min_val_pos = i;
        // Look for smaller unsorted value
        for (int j = i + 1; j < length; j++) {
            if (array[j] < array[min_val_pos]) {
                min_val_pos = j;
            }
        }
        // Swap smaller value to the front if found and set it as sorted
        if (min_val_pos != i)
        {
            int temp;
            temp = array[i];
            array[i] = array[min_val_pos];
            array[min_val_pos] = temp;
        }
    }
}