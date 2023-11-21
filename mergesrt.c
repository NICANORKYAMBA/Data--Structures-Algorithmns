#include <stdio.h>
#include <stdlib.h>

void merge(int *array, int lb, int mid, int ub);
void mergesort(int *array, int lb, int ub);
void printarray(int *array, int size);


/**
 * printarray - prints an array of integers
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
 * mergesort - sorts an array of integers using merge sort
 *
 * @array: array to sort
 * @lb: lower bound of the array
 * @ub: upper bound of the array
 *
 * Return: void
 */
void mergesort(int *array, int lb, int ub)
{
	int mid;

	if (lb < ub)
	{
		mid = (lb + ub) / 2;
		mergesort(array, lb, mid);
		mergesort(array, mid + 1, ub);
		merge(array, lb, mid, ub);
	}
}

/**
 * merge - merges two sorted arrays
 *
 * @array: array to merge
 * @lb: lower bound of the array
 * @mid: middle of the array
 * @ub: upper bound of the array
 *
 * Return: void
 */
void merge(int *array, int lb, int mid, int ub)
{
	int i, j, k, size;
	int *temp;

	i = lb;
	j = mid + 1;
	k = 0;
	size = ub - lb + 1;

	temp = malloc(sizeof(int) * size);

	if (!temp)
	{
		return;
	}

	while (i <= mid && j <= ub)
	{
		if (array[i] <= array[j])
		{
			temp[k] = array[i];
			i++;
		}
		else
		{
			temp[k] = array[j];
			j++;
		}
		k++;
	}

	if (i > mid)
	{
		while (j <= ub)
		{
			temp[k] = array[j];
			j++;
			k++;
		}
	}
	else
	{
		while (i <= mid)
		{
			temp[k] = array[i];
			i++;
			k++;
		}
	}

	for (k = 0; k < size; k++)
	{
		array[lb + k] = temp[k];
	}

	free(temp);
}

/**
 * main - entry point
 *
 * Return: 0
 */
int main(void)
{
	int array[] = {10, 97, 88, 71, 64, 59, 43, 13, 22, 101};

	printf("Unsorted array: \n");
	printarray(array, 10);
	printf("\n");

	mergesort(array, 0, 9);

	printf("\n");
	printf("Sorted array: \n");
	printarray(array, 10);

	return (0);
}
