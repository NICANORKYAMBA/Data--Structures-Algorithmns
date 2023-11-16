#ifndef _SORT_H
#define _SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

char *insertion_sort(char *str, size_t size);
void nearestNeighbor(int start);
int partition(int array[], int low, int high);
void quicksort(int array[], int low, int high);
void printArray(int array[], int size);

#endif
