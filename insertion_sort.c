#include "sort.h"

void swap(char *a, char *b);

/**
 * insertion_sort - sorts an array of characters using insertion sort
 *	in ascending order
 *
 * @str: array of characters to be sorted
 * @size: size of the array
 *
 * Return: sorted array
 */
char *insertion_sort(char *str, size_t size)
{
	size_t i, j;

	for (i = 1; i < size; i++)
	{
		j = i;

		while ((j > 0) && (str[j] < str[j - 1]) &&
				(str[j] != ' ' && str[j + 1] != ' ')
				&& (str[j] != '\0' && str[j + 1] != '\0'))
		{
			swap(&str[j], &str[j - 1]);
			j--;
		}
	}

	return (str);
}

/**
 * swap - swaps two characters in an array
 *
 * @a: first character
 * @b: second character
 *
 * Return: void
 */
void swap(char *a, char *b)
{
	char tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
