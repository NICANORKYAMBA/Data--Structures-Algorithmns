#include "sort.h"


#define SIZE 30

void print_array(char *array, int size);

/**
 * main - check the code
 *
 * Return: Always 0
 */
int main(void)
{
	char *sorted_array;
	char *sorted_array2;

	char unsorted_array[SIZE] = "INSERTION SORT TEST";
	char unsorted_array2[SIZE] = "racing car, yellow poster";

	printf("Original Array:\n");
	print_array(unsorted_array, SIZE);

	sorted_array = insertion_sort(unsorted_array, SIZE);

	printf("Sorted Array:\n");
	print_array(sorted_array, SIZE);

	printf("Original Array:\n");
	print_array(unsorted_array2, SIZE);

	sorted_array2 = insertion_sort(unsorted_array2, SIZE);

	printf("Sorted Array:\n");
	print_array(sorted_array2, SIZE);

	return (0);
}

/**
 * print_array - prints an array
 *
 * @array: array to be printed
 * @size: size of the array
 *
 * Return: void
 */
void print_array(char *array, int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		printf("%c ", array[i]);
	}
	printf("\n");
}
