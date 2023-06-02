#include "main.h"

/**
 * is_printable - Evaluates if a char is printable
 * @g: Char to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int is_printable(char g)
{
	if (g >= 32 && g < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Append ascci in hexadecimal code to buffer
 * @buffer: Array of chars.
 * @f: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int f)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[f++] = '\\';
	buffer[f++] = 'x';

	buffer[f++] = map_to[ascii_code / 16];
	buffer[f] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Verifies if a char is a digit
 * @k: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char k)
{
	if (k >= '0' && k <= '9')
		return (1);

	return (0);
}
/**
 * convert_size_number - Casts a number to the specified size
 * @num: Number to be casted.
 * @p: Number indicating the type to be casted.
 *
 * Return: Casted value of num
 */
long int convert_size_number(long int num, int p)
{
	if (p == S_LONG)
		return (num);
	else if (p == S_SHORT)
		return ((short)num);

	return ((int)num);
}
/**
 * convert_size_unsgnd - Casts a number to the specified size
 * @num: Number to be casted
 * @t: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int convert_size_unsgnd(unsigned long int num, int t)
{
	if (t == S_LONG)
		return (num);
	else if (t == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
