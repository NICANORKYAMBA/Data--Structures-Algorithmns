#include <stdio.h>
#include <stdbool.h>

void swap(int *a, int *b);
void printarray(int *array, int size);
void bubblesort(int *array, int size);

/**
 * main - entry function
 *
 * Return: int
 */
int main(void)
{
	int size;
	int array[] = {56, 23, 78, 5, 66, 92, 88, 30, 47};

	size = sizeof(array) / sizeof(array[0]);

	printf("Unsorted array: \n");
	printarray(array, size);
	printf("\n");

	bubblesort(array, size);

	printf("\n");
	printf("Sorted array: \n");
	printarray(array, size);

	return (0);
}

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
 * printarray - function to display the array
 *
 * @array: array to print
 * @size: size of the array
 *
 * Return: void
 */
void printarray(int *array, int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}

	printf("\n");
}

/**
 * bubblesort - function to sort an array using bubble sort
 *	algorithm
 *
 * @array: list of numbers to sort
 * @size: size of the list
 *
 * Return: void
 */
void bubblesort(int *array, int size)
{
	int i, j;
	bool swapped;

	for (i = 0; i < size - 1; i++)
	{
		swapped = false;

		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				printarray(array, size);
				swapped = true;
			}
		}

		if (swapped == false)
			break;
	}
}
