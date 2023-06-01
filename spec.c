#include "main.h"
/**
 * get_spec - finds the format function
 * @s: the string forma
 *
 * return: the num of bytes printed
 */
int (*get_spe(char *s))(va_list ao, params_t *params)
{
      spec_t spec[] = {
	      {"c", print_char},
	      {"d", print_int},
	      {"i", print_int},
	      {"s", print_string},
	      {"%", print_precent},
	      {"b", print_binary},
	      {"o", print_octal},
	      {"u", print_unsigned},
	      {"x", print_hex},
	      {"x", print_HEX},
	      {"p", print_address},
	      {"s", print_S},
	      {"r", print_rev},
	      {"R", print_rot13},
	      {NULL, NULL}
      };
      int i = 0;
      while (spe[i].spe)
      {
        if (*s == spe[i].spe[0])
	{
             return (spe[i].f);
	}
        i++;
      }
      return
