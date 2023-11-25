#include "file.h"

/**
 * processWord - process a single word and update word frequencies
 *
 * @word: word to process
 * @wordFrequencies: array of word frequencies
 * @index: current index in the array
 * @maxFrequency: maximum frequency encountered so far
 * @mostFrequentWord: pointer to most frequent word
 *
 * Return: updated maxFrequency
 */
static int processWord(char *word, wordFrequency *wordFrequencies, int *index,
		int maxFrequency, char *mostFrequentWord)
{
	int currentFrequency, i;

	currentFrequency = 1;

	for (i = 0; i < *index; i++)
	{
		if (strcmp(word, wordFrequencies[i].word) == 0)
		{
			currentFrequency = ++wordFrequencies[i].frequency;
			break;
		}
	}

	if (i == *index)
	{
		strcpy(wordFrequencies[*index].word, word);
		wordFrequencies[*index].frequency = currentFrequency;
		(*index)++;
	}

	if (currentFrequency > maxFrequency)
	{
		maxFrequency = currentFrequency;
		strcpy(mostFrequentWord, wordFrequencies[i].word);
	}

	printf("Processed Word: %s, Frequency: %d\n", word, currentFrequency);

	return (maxFrequency);
}

/**
 * tokenizeLine - tokenize a line into words and process each word
 *
 * @line: line to tokenize
 * @wordFrequencies: array of word frequencies
 * @index: current index in the array
 * @maxFrequency: maximum frequency encountered so far
 * @mostFrequentWord: pointer to most frequent word
 *
 * Return: updated maxFrequency
 */
static int tokenizeLine(char *line, wordFrequency *wordFrequencies,
		int *index, int maxFrequency, char *mostFrequentWord)
{
	char *token = strtok(line, " \t\n");

	while (token)
	{
		int len = strlen(token);
		char word[MAX_WORD_LENGTH];
		int k, j = 0;

		for (k = 0; k < len; k++)
		{
			if (isalpha(token[k]))
			{
				word[j++] = tolower(token[k]);
			}
		}

		word[j] = '\0';

		maxFrequency = processWord(word, wordFrequencies, index,
				maxFrequency, mostFrequentWord);

		token = strtok(NULL, " \t\n");
	}

	return (maxFrequency);
}

/**
 * findmostfrequentword - finds the most frequent word in a file
 *
 * @file: pointer to beginning of the file
 * @mostFrequentWord: pointer to most frequent word
 * @frequency: *frequecy of the word
 *
 * Return: (void)
 */
void findmostfrequentword(FILE *file, char *mostFrequentWord, int *frequency)
{
	char line[MAX_LINE_LENGTH];
	int maxFrequency = 0;
	int index = 0;
	wordFrequency wordFrequencies[1000];

	while (fgets(line, sizeof(line), file) != NULL)
	{
		maxFrequency = tokenizeLine(line, wordFrequencies, &index,
				maxFrequency, mostFrequentWord);
	}

	*frequency = maxFrequency;
}
