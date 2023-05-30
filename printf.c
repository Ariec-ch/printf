#include "main.h"

void print_buffer(char buffer[], int *buff_i);

/**
 * _printf - Printf function
 * @form: format.
 * Return: Printed chars.
 */
int _printf(const char *form, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_i = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (form == NULL)
		return (-1);

	va_start(list, form);

	for (i = 0; form && form[i] != '\0'; i++)
	{
		if (form[i] != '%')
		{
			buffer[buff_i++] = form[i];
			if (buff_i == BUFF_SIZE)
				print_buffer(buffer, &buff_i);
			/* write(1, &form[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_i);
			flags = get_flags(form, &i);
			width = get_width(form, &i, list);
			precision = get_precision(form, &i, list);
			size = get_size(form, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_i);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_i: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_i)
{
	if (*buff_i > 0)
		write(1, &buffer[0], *buff_i);

	*buff_i = 0;
}

