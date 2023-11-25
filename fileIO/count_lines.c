#include "file.h"

/**
 * countlines - counts lines in a file
 *
 * @file: file pointer
 *
 * Return: count of lines in a file
 */
int countlines(FILE *file)
{
	int count = 0;
	char line[MAX_LINE_LENGTH];

	while (fgets(line, MAX_LINE_LENGTH, file))
	{
		count++;
	}

	rewind(file);

	return (count);
}
