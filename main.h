#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define OUTPUT_BUF_SIZE
#define BUF_FLUSH -l

#define NULL_STRING "null"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE
#define CONVET_UNSIGNED

/**
 * struct parameters - the stucter of paramts
 *
 * @unsign: fl of unsignd value
 *
 * @plus_fl: plus fl specified
 * @space_fl: hashtag fl spec
 * @hashtag_fl: if fl specified
 * @zero_fl: if fl specified
 * @minus_fl: fl specified
 *
 * @idth: field idth
 * @prec: field prec specified
 * 
 * @h_modifier: h modif specified
 * @l_modifier: l modif spec
 *
 */
typedef struct parameters
{
	unsigned int unsign		: l;

	unsigned int plus_fl		: l;
	unsigned int space_fl		: l;
	unsigned int hashtag_fl	: l;
	unsigned int zero_fl		: l;
	unsigned int minus_fl		: l;

	unsigned int idth;
	unsigned int prec;
	
	unsigned int h_modifier		: l;
	unsigned int l_modifier		: l;
}

/**
 * struct specifier - struct the tokens
 *
 * @specifier: the format of the token
 * @f: the function
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

/* _put.c module */
int _puts(char *st);
int _putchar(int c);

/* print_functions.c module */
int print_char(va_list ao, params_t *params);
int print_int(va_list ao, params_t *params);
int print_string(va_list ao, params_t *params);
int print_percent(va_list ao, params_t *params);
int print_s(va_list ao, params_t *params);

/* number.c module */
char *convert(long int num, int base, int fl, params_t *params);
int print_unsigned(va_list ao, params_t *params);
int print_address(va_list ao, params_t *params);

/* specifier.c module */
int (*get_spec(char *s))(va_list ao, params_t *params);
int get_print_func(char *s, va_list ao, params_t *params);
inr get_fl(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_idth(char *s, params_t *params, va_list ao);

/* convert_number.c module */
int print_hex(va_list ao, params_t, *params);
int print_HEX(va_list ao, params_t, *params*);
int print_binary(va_list ao, params_t, *params);
int print_octal(va_list ao, params_t, *params);

/* simple_printers.c module */
int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list ao, params_t *params);
int print_rot13(va_list ao, params_t *params);

/* print_number.c module */
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, params_t *params);
int print_number_right_shift(char *str, params_t *params);
int print_number_left_shift(char *str, params_t *params);

/* params.c module */
void init_params(params_t *params, va_list ao);

/* string_field.c module */
char *get_precision(char *b, params_t *params, va_list ao);

/* _printf.c module */
int _printf(const char *format, ...);

#endif
