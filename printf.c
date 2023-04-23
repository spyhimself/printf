#include "main.h"

/**
 * _printf - is a function that determines which function to print.
 * @format: Look for the identification.
 * Return: the string's overall length.
 */

int _printf(const char * const format, ...)
{
	convert_match m[] = {
		{"%s", printf_string}, {"%c", printf_char},
		{"%%", printf_37},
		{"%i", printf_int}, {"%d", printf_dec}, {"%r", printf_srev},
		{"%R", printf_rot13}, {"%b", printf_bin}, {"%u", printf_unsigned},
		{"%o", printf_oct}, {"%x", printf_hex}, {"%X", printf_HEX},
		{"%S", printf_exclusive_string}, {"%p", printf_pointer}
	};

	va_list args;
	int i = 0, f, len = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

Here:
	while (format[i] != '\0')
	{
		f = 13;
		while (f >= 0)
		{
			if (m[f].id[0] == format[i] && m[f].id[1] == format[i + 1])
			{
				len += m[f].f(args);
				i = i + 2;
				goto Here;
			}
			f--;
		}
		_putchar(format[i]);
		len++;
		i++;
	}
	va_end(args);
	return (len);
}
