#include "main.h"

/*Ayyoub Chentih && Aymen Tarar */

/**
 * _puts - a string is printed with a newline
 * @str: the string to be printed
 *
 * Return: void
 */
int _puts(char *str)
{
	char *a = str;

	while (*str)
		_putchar(*str++);
	return (str - a);
}

/**
 * _putchar - stdout receives the character c
 * @c: The character to be printed
 *
 * Return: On success 1.
 * On error, The value -1 is returned, and errno is suitably set.
 */
int _putchar(int c)
{
	static int i;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
