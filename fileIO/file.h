#ifndef _FILE_H
#define _FILE_H

#define MAX_WORD_LENGTH 200
#define MAX_LINE_LENGTH 256

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct wordFrequency - structure to store word frequency in a file
 *
 * @word: array of words
 * @frequency: number of times the word is found
 */
typedef struct wordFrequency
{
	char word[MAX_WORD_LENGTH];
	int frequency;
} wordFrequency;

int countwords(char *line);
int countlines(FILE *file);
float averagewordlength(FILE *file, int totalWords);
void findmostfrequentword(FILE *file, char *mostFrequentWord, int *frequency);

#endif
