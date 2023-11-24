#include <stdio.h>

/**
 * struct car - car data type
 *
 * @name: name of the car
 * @price: price of the car
 * @speed: speed of the car
 */
typedef struct car {
	char *name;
	float price;
	int speed;
} car;

/**
 * main - entry point
 *
 * Return: 0
 */
int main(void)
{
	car saturn;

	saturn.name = "Saturn SL/2";
	saturn.price = 999.99;
	saturn.speed = 300;

	printf("Model: %s\n", saturn.name);
	printf("Price: %f\n", saturn.price);
	printf("Speed: %d\n", saturn.speed);

	return (0);
}
