#include "sort.h"

/**
 * main - Entry function
 *
 * Return: 0
 */
int main(void)
{
	int n;
	int array[] = {64, 25, 12, 22, 11};

	n = sizeof(array) / sizeof(array[0]);

	printf("Unsorted array: ");
	printArray(array, n);

	quicksort(array, 0, n - 1);

	printf("Sorted array: ");
	printArray(array, n);

	return (0);
}
