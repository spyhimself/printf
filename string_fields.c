#include "main.h"

/**
 * get_precision - the precision is derived from the format string
 * @p: formatting string
 * @params: the structure of parameters
 * @ap: argument pointing
 *
 * Return: new pointing device
 */
char *get_precision(char *p, params_t *params, va_list ap)
{
	int l = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		l = va_arg(ap, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			l = l * 10 + (*p++ - '0');
	}
	params->precision = l;
	return (p);
}
