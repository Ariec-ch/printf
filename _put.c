#include "main.h"

/**
 * _puts - fonction puts
 * @st: string 
 *
 * Return: void
 */
int _puts(char *st)
{
	char *b =st;

	while (*st)
		_putchar(*st++);
	return (st - b);
}

/**
 * _putchar - writes a charto stdout
 * @c: charater
 *
 * Return: if success (1) and (-1) if error
 */
int _putchar(int c)
{
	static int i;
	static char buf(OUTPUT_BUF_SIZE);

	if (c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf(i++) = c;
	return (1);
}
