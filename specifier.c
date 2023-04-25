#include "main.h"

/**
 * get_specifier - discovers the format function
 * @s: string format
 *
 * Return: the quantity of bytes printed
 */

int (*get_specifier(char *s))(va_list ap, params_t *params)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * get_print_func - identifies the format function
 * @s: string format
 * @ap: pointer to an argument
 * @params: the parameters structure
 *
 * Return: the quantity of bytes printed
 */

int get_print_func(char *s, va_list ap, params_t *params)
{
	int (*f)(va_list, params_t *) = get_specifier(s);

	if (f)
		return (f(ap, params));
	return (0);
}

/**
 * get_flag - discovers the flag function
 * @s: formatting string
 * @params: the structure of parameters
 *
 * Return: if the flag was correct
 */

int get_flag(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = params->plus_flag = 1;
			break;
		case ' ':
			i = params->space_flag = 1;
			break;
		case '#':
			i = params->hashtag_flag = 1;
			break;
		case '-':
			i = params->minus_flag = 1;
			break;
		case '0':
			i = params->zero_flag = 1;
			break;
	}
	return (i);
}

/**
 * get_modifier - discovers the modifier function
 * @s: string format
 * @params: the structure of parameters
 *
 * Return: whether the modification was correct
 */

int get_modifier(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
	case 'h':
		i = params->h_modifier = 1;
		break;
	case 'l':
		i = params->l_modifier = 1;
		break;
	}
	return (i);
}

/**
 * get_width - the width is derived from the format string
 * @s: formatting string
 * @params: the parameters structure
 * @ap: the argument arrow
 *
 * Return: new pointing device
 */

char *get_width(char *s, params_t *params, va_list ap)
{
	int r = 0;

	if (*s == '*')
	{
		r = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			r = r * 10 + (*s++ - '0');
	}
	params->width = r;
	return (s);
}
