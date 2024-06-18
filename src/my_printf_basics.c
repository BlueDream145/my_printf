/*
** EPITECH PROJECT, 2017
** my_printf_basics.c
** File description:
**
*/

#include <stdlib.h>
#include <stdarg.h>
#include "../include/print.h"

void my_print_string(char *arg, va_list ap, char *exceed, int index)
{
	if (exceed == NULL || arg[index] != 's')
		return;
	my_put_str((const char*)va_arg(ap, char *));
}

void my_print_char(char *arg, va_list ap, char *exceed, int index)
{
	if (exceed == NULL || arg[index] != 'c')
		return;
	my_put_char(va_arg(ap, int));
}

void my_print_special_string(char *arg, va_list ap, char *exceed, int index)
{
	if (exceed == NULL || arg[index] != 'S')
		return;
	my_put_special_base_str(va_arg(ap, char*));
}

void my_print_octal(char *arg, va_list ap, char *exceed, int index)
{
	int nbr;

	if (exceed == NULL || arg[index] != 'o')
		return;
	nbr = va_arg(ap, int);
	my_put_nbr(convert_octal(manage_param_space(nbr, exceed, 0)));
	manage_param_space(nbr, exceed, 1);
}

void my_print_scientific(char *arg, va_list ap, char *exceed, int index)
{
	if (exceed == NULL)
		return;
	if (arg[index] == 'e')
		convert_scientific(va_arg(ap, double), 0);
	else if (arg[index] == 'E')
		convert_scientific(va_arg(ap, double), 1);
}