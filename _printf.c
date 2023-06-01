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
	char *p, *start;
	params_t params = PARAMS_INIT;

	va_start(aon, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *) format; *p; p++)
	{
		init _params(&params, ao);
		if (*p != '%')
		{
			sm += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (get_fl(p, &params)) /*while char at p is flag char */
		{
			p++; /* next char */
		}
		p = get_idth(p, &params, ao);
		p = get_prec(p, &params, ao);
		if (get_modifier(p, &params))
			p++;
		if (!get_specifier(p))
			sm += print_from_to(start, p,
					params.l_modifier || params.h_modifier ? p - 1 : 0);
		else
			sm += get_print_func(p, ao, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(ao);
	return (sm);
}
