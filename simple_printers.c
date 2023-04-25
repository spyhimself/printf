#include "main.h"

/**
 * print_from_to - a range of char addresses is printed
 * @start: beginning point
 * @stop: halting location
 * @except: except for address
 *
 * Return: the amount of bytes printed
 */

int print_from_to(char *start, char *stop, char *except)
{
	int sum = 0;

	while (start <= stop)
	{
		if (start != except)
			sum += _putchar(*start);
		start++;
	}
	return (sum);
}

/**
 * print_rev - returns the string in reverse
 * @ap: string
 * @params: the parameters structure
 *
 * Return: the amount of bytes printed
 */

int print_rev(va_list ap, params_t *params)
{
	int ln, sum = 0;
	char *str = va_arg(ap, char *);
	(void)params;

	if (str)
	{
		for (ln = 0; *str; str++)
			ln++;
		str--;
		for (; ln > 0; ln--, str--)
			sum += _putchar(*str);
	}
	return (sum);
}

/**
 * print_rot13 - string is printed in rot13
 * @ap: string
 * @params: the parameters structure
 *
 * Return: the amount of bytes printed
 */

int print_rot13(va_list ap, params_t *params)
{
	int i, index;
	int count = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(ap, char *);
	(void)params;

	i = 0;
	index = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
		    || (a[i] >= 'a' && a[i] <= 'z'))
		{
			index = a[i] - 65;
			count += _putchar(arr[index]);
		}
		else
			count += _putchar(a[i]);
		i++;
	}
	return (count);
}
