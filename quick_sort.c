#include "sort.h"

void swap(int *a, int *b);
/**
 * swap - function to swap two elements
 *
 * @a: first element
 * @b: second element
 *
 * Return: void
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - function to sort array into two subarrays
 *
 * @array: array to partition
 * @low: lower values
 * @high: higer values
 *
 * Return: partitioned arrays
 */
int partition(int array[], int low, int high)
{
	int pivot, i, j;

	pivot = array[high];

	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}

	swap(&array[i + 1], &array[high]);

	return (i + 1);
}

/**
 * quicksort - function to quick sort an array
 *
 * @array: array to sort
 * @low: lower values of the array
 * @high: higher values of the array
 *
 * Return: void
 */
void quicksort(int array[], int low, int high)
{
	int pivotIndex;

	if (low < high)
	{
		pivotIndex = partition(array, low, high);

		quicksort(array, low, pivotIndex - 1);
		quicksort(array, pivotIndex + 1, high);
	}
}
