#include "sort.h"

#define NUM_CITIES 10

int distance[NUM_CITIES][NUM_CITIES] = {
	{0, 10, 15, 20, 25, 30, 35, 40, 45, 50},
	{10, 0, 5, 10, 15, 20, 25, 30, 35, 40},
	{15, 5, 0, 5, 10, 15, 20, 25, 30, 35},
	{20, 10, 5, 0, 5, 10, 15, 20, 25, 30},
	{25, 15, 10, 5, 0, 5, 10, 15, 20, 25},
	{30, 20, 15, 10, 5, 0, 5, 10, 15, 20},
	{35, 25, 20, 15, 10, 5, 0, 5, 10, 15},
	{40, 30, 25, 20, 15, 10, 5, 0, 5, 10},
	{45, 35, 30, 25, 20, 15, 10, 5, 0, 5},
	{50, 40, 35, 30, 25, 20, 15, 10, 5, 0}
};

int visited[NUM_CITIES];

/**
 * main - entry point
 *
 * Return: 0
 */
int main(void)
{
	nearestNeighbor(0);

	return (0);
}

/**
 * nearestNeighbor - prints the tour of a nearest neighbor algorithm
 *
 * @start: starting city
 *
 * Return: void
 */
void nearestNeighbor(int start)
{
	int current, minDistance, nextCity;
	int count, i;

	current = start;

	printf("Tour: %d", current + 1);

	visited[current] = 1;

	for (count = 1; count < NUM_CITIES; count++)
	{
		minDistance = INT_MAX;
		nextCity = -1;

		for (i = 0; i < NUM_CITIES; i++)
		{
			if (!visited[i] && distance[current][i] < minDistance)
			{
				minDistance = distance[current][i];
				nextCity = i;
			}
		}

		if (nextCity != -1)
		{
			printf(" -> %d", nextCity + 1);
			visited[nextCity] = 1;
			current = nextCity;
		}
	}

	printf(" -> %d", start + 1);

	printf("\n");
}
