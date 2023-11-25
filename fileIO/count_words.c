#include "file.h"

/**
 * countwords - counts words in file
 *
 * @line: file pointer
 *
 * Return: count of words in a file
 */
int countwords(char *line)
{
	int count = 0;
	char *token = strtok(line, " ");

	while (token)
	{
		count++;
		token = strtok(NULL, " ");
	}

	return (count);
}
