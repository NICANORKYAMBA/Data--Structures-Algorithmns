#include <stdio.h>

void swap(int *a, int *b);

/**
 * partition - function to partition an array to sub arrays
 *
 * @array: array to subdivide and sort
 * @lb: lower bound
 * @ub: upper bound
 *
 * Return: index value of the end
 */
int partition(int *array, int lb, int ub)
{
	int pivot, start, end;

	pivot = array[lb];
	start = lb;
	end = ub;

	while (start < end)
	{
		while (array[start] <= pivot)
		{
			start++;
		}

		while (array[end] > pivot)
		{
			end--;
		}

		if (start < end)
		{
			swap(&array[start], &array[end]);
		}
	}

	swap(&array[lb], &array[end]);

	return (end);
}

/**
 * swap - function to swap two elements
 *
 * @a: first element
 * @b: second element
 *
 * Return: Void
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * quicksort - function to quickly sort an array
 *
 * @array: array to quick sort
 * @lb: lower bound
 * @ub: upper bound
 *
 * Return: Void
 */
void quicksort(int *array, int lb, int ub)
{
	int loc;

	if (lb < ub)
	{
		loc = partition(array, lb, ub);

		quicksort(array, lb, loc - 1);

		quicksort(array, loc + 1, ub);
	}
}

/**
 * printarray - function to print an array
 *
 * @array: array to print
 * @size: size of the array
 *
 * Return: Void
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
 * main - entry function
 *
 * Return: int
 */
int main(void)
{
	int n;
	int array[] = {23, 55, 96, 24, 109, 41, 10, 0, 1, 67, 5, 85, 74, 60, 75, 99};

	n = sizeof(array) / sizeof(array[0]);

	printf("Array before sorting: \n");

	printarray(array, n);

	quicksort(array, 0, n - 1);

	printf("Array after sorting: \n");

	printarray(array, n);

	return (0);
}
