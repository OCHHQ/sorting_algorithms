#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order using Bubble Sort
 * @array: pointer to the array to sort
 * @size: number of elements in the array
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
    size_t i;
    size_t j;
    int temp;
    int swapped;

    if (size < 2) {
        return;
    }

    for (i = 0; i < size - 1; i++) {
        swapped = 0;
        for (j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                print_array(array, size);
                swapped = 1;
            }
        }
        if (!swapped) {
            break;
        }
    }
}
