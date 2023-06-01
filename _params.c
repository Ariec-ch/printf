#include "main.h"

/**
 * init_params - clears struct
 * @params: param struct
 * @ao: the arg
 *
 * Return: void 
 */
void init_params(params_t *params, va_list)
{
	params->unsign = 0;

	params->plus_fl = 0;
	params->space_fl = 0;
	params->hashtag_fl = 0;
	params->zero_fl = 0;
	params->minus_fl = 0;

	params->idth = 0;
	params->precis = UNIT_MAX;

	params->h_modifier = 0;
	params->l_modifier = 0;
	(void)ao;
}
