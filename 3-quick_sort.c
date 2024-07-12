#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two integers in an array
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
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
	int pivot;
	int i;
	int j;

	pivot = array[high];
	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if ((i + 1) != high)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	int low;
	int high;
	int pivot_index;

	if (size < 2)
		return;

	low = 0;
	high = size - 1;

	pivot_index = lomuto_partition(array, low, high, size);

	if (pivot_index > low + 1)
		quick_sort(array, pivot_index);

	if (pivot_index < high - 1)
		quick_sort(array + pivot_index + 1, size - pivot_index - 1);
}
