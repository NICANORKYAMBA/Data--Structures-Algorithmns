#include "file.h"

/**
 * main - entry function
 *
 * Return: 0
 */
int main(void)
{
	FILE *inputFile, *outputFile;
	char line[MAX_LINE_LENGTH];
	int totalWords, totalLines;
	float avgWordLen;
	char mostFrequentWord[MAX_WORD_LENGTH];
	int frequency;

	inputFile = fopen("input.txt", "r");

	if (!inputFile)
	{
		perror("Error opening input file");
		return (1);
	}

	outputFile = fopen("output.txt", "w");

	if (!outputFile)
	{
		perror("Error opening output file");
		fclose(inputFile);
		return (1);
	}

	totalWords = 0;

	while (fgets(line, MAX_LINE_LENGTH, inputFile))
	{
		totalWords += countwords(line);
	}

	totalLines = 0;

	rewind(inputFile);

	while (fgets(line, MAX_LINE_LENGTH, inputFile))
	{
		totalLines++;
	}

	avgWordLen = (float)totalWords / totalLines;

	findmostfrequentword(inputFile, mostFrequentWord, &frequency);

	fprintf(outputFile, "Word Count: %d\n", totalWords);
	fprintf(outputFile, "Line Count: %d\n", totalLines);
	fprintf(outputFile, "Average Word Length: %.3f\n", avgWordLen);
	fprintf(outputFile, "Most Frequent Word: \"%s\" (%d times)\n", mostFrequentWord, frequency);

	fclose(inputFile);
	fclose(outputFile);

	return (0);
}
