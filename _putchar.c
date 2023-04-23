#include "main.h"

/*Ayyoub Chentih && Aymen Tarar */

/**
 * _putchar - stdout receives the character c
 * @c: The printed character
 * Return: Regarding success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
