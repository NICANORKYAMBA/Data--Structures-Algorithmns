#include <stdio.h>

/**
 * struct car - car data type
 *
 * @name: name of the car
 * @price: price of the car
 * @speed: speed of the car
 */
struct car {
	char *name;
	float price;
	int speed;
};

/**
 * main - entry point
 *
 * Return: 0
 */
int main(void)
{
	struct car saturn;

	saturn.name = "Saturn SL/2";
	saturn.price = 799.99;
	saturn.speed = 175;

	printf("Model: %s\n", saturn.name);
	printf("Price: %f\n", saturn.price);
	printf("Speed: %d\n", saturn.speed);

	return (0);
}
