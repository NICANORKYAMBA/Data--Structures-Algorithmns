#include <stdio.h>

void selectionsort(int *array, int size);
void swap(int *a, int *b);
void printarray(int *array, int size);

/**
 * selectionsort - sorts an array of integers in ascending order
 *
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void selectionsort(int *array, int size)
{
	int i, j, min;

	for (i = 0; i < size - 1; i++)
	{
		min = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}

		if (min != i)
		{
			swap(&array[i], &array[min]);
			printarray(array, size);
		}
	}
}

/**
 * swap - swaps two integers
 *
 * @a: first integer
 * @b: second integer
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
 * printarray - prints an array of integers
 *
 * @array: array to be printed
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
 * main - entry point
 *
 * Return: 0 (Success)
 */
int main(void)
{
	int size;
	int array[] = {345, 879, 236, 676, 911, 119, 25, 766, 105, 51, 5, 22};

	size = sizeof(array) / sizeof(array[0]);

	printf("Unsorted Array: \n");
	printarray(array, size);
	printf("\n");

	selectionsort(array, size);

	printf("\n");
	printf("Sorted Array: \n");
	printarray(array, size);

	return (0);
}
