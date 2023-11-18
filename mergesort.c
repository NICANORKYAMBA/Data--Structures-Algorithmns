#include <stdio.h>
#include <stdlib.h>

void merge(int *array, int left, int middle, int right);
void printarray(int *array, int size);

/**
 * mergesort - sorts an array using mergesort algorithm
 *
 * @array: array to be sorted
 * @left: left index of the array
 * @right: right index of the array
 *
 * Return: void
 */
void mergesort(int *array, int left, int right)
{
	int middle;

	middle = (left + right) / 2;

	if (left < right)
	{
		mergesort(array, left, middle);
		mergesort(array, middle + 1, right);

		merge(array, left, middle, right);
	}
}

/**
 * merge - merges two sorted arrays
 *
 * @array: array to be sorted
 * @left: left index of the array
 * @middle: middle index of the array
 * @right: right index of the array
 *
 * Return: void
 */
void merge(int *array, int left, int middle, int right)
{
	int n1, n2, i, j, k;
	int *L, *R;

	n1 = middle - left + 1;
	n2 = right - middle;

	L = malloc(n1 * sizeof(int));
	R = malloc(n2 * sizeof(int));

	for (i = 0; i < n1; i++)
	{
		L[i] = array[left + i];
	}

	for (j = 0; j < n2; j++)
	{
		R[j] = array[middle + 1 + j];
	}

	i = 0;
	j = 0;
	k = left;

	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			array[k] = L[i];
			i++;
		}
		else
		{
			array[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		array[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		array[k] = R[j];
		j++;
		k++;
	}

	free(L);
	free(R);
}

/**
 * printarray - prints an array
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
 * Return: 0
 */
int main(void)
{
	int n;
	int array[] = {12, 11, 13, 5, 6, 7, 9, 66, 89, 74};

	n = sizeof(array) / sizeof(array[0]);

	printf("Unsorted Array: \n");
	printarray(array, n);

	mergesort(array, 0, n - 1);

	printf("Sorted array: \n");
	printarray(array, n);

	return (0);
}
