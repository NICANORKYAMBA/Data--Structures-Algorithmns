#ifndef _STRUCT_H
#define _STRUCT_H

#include <stdio.h>

/**
 * struct car - car data type
 *
 * @name: name of the car
 * @price: price of the car
 * @speed: speed of the car
 */
typedef struct car
{
	char *name;
	float price;
	int speed;
} car;

void update_car(car *c, char *newname, float newprice, int newspeed);

#endif
