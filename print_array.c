#include "sort.h"

/**
 * printArray - prints an array
 *
 * @array: array to print
 * @size: size of the array
 *
 * Return: void
 */
void printArray(int array[], int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}
