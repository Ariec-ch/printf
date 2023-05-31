#include "main.h"


/**
 * _printf - Print a text
 * @format: string
 *
 * Return: numb of bytes
 */
int _printf(const char *format, ...)
{
	int sm = 0;
	va_list ao;
	char *j, *start;
	params_t params = PARAMS_INIT;

	va_start(aon, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (j = (char *) format; *j; j++)
	{
		init _params(&params, ao);
		if (*j != '%')
		{
			sm += _putchar(*j);
			continue;
		}
		start = j;
		j++;
		while (get_flag(j, &params)) /*while char at j is flag char */
		{
			j++; /* next char */
		}
		j = get_width(j, &params, ao);
		j = get_precision(j, &params, ao);
		if (get_modifier(j, &params))
			j++;
		if (!get_specifier(j))
			sm += print_from_to(start, j,
					params.l_modifier || params.h_modifier ? j - 1 : 0);
		else
			sm += get_print_func(j, ao, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(ao);
	return (sm);
}
