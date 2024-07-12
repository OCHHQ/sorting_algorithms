#include "sort.h"

/**
 * swap - Swaps two integers in an array
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick sort
 * @array: Array to be sorted
 * @low: Starting index of the partition to be sorted
 * @high: Ending index of the partition to be sorted
 * @size: Size of the array
 * Return: Index of the pivot element after sorting
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            if (i != j)
            {
                swap(&array[i], &array[j]);
                print_array(array, size);
            }
        }
    }

    if (array[high] < array[i + 1])
    {
        swap(&array[i + 1], &array[high]);
        print_array(array, size);
    }

    return (i + 1);
}

/**
 * lomuto_sort - Helper function for recursive sorting using Lomuto partition
 * @array: Array to be sorted
 * @low: Starting index of the partition to be sorted
 * @high: Ending index of the partition to be sorted
 * @size: Size of the array
 */
void lomuto_sort(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pivot_index = lomuto_partition(array, low, high, size);

        lomuto_sort(array, low, pivot_index - 1, size);
        lomuto_sort(array, pivot_index + 1, high, size);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (size < 2)
        return;

    lomuto_sort(array, 0, size - 1, size);
}
