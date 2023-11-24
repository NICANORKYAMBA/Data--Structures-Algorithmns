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

void update_car(car *c, char *newname, float newprice, int newspeed);

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

	update_car(&saturn, "Toyota Model",1990.89, 450);

	printf("\nNew Model: %s\n", saturn.name);
	printf("New Price: %f\n", saturn.price);
	printf("New Speed: %d\n", saturn.speed);

	return (0);
}

/**
 * update_car - function to update the car
 *
 * @newname: new name to the car model
 * @newprice: price of the new model
 * @newspeed: new speed of the updated car
 *
 * Return: (void)
 */
void update_car(car *c, char *newname, float newprice, int newspeed)
{
	c->name = newname;
	c->price = newprice;
	c->speed = newspeed;
}
