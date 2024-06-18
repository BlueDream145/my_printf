/*
** EPITECH PROJECT, 2017
** my_printf_decimal.c
** File description:
**
*/

#include <stdlib.h>
#include <stdarg.h>
#include "../include/print.h"

void my_print_float(char *arg, va_list ap, char *exceed, int index)
{
	if (exceed == NULL || (arg[index] != 'f' && arg[index] != 'F'))
		return;
	my_put_float(manage_sign(arg, va_arg(ap, double)));
}

void my_print_binary(char *arg, va_list ap, char *exceed, int index)
{
	if (exceed == NULL || (arg[index] != 'b' && arg[index] != 'B'))
		return;
	my_putnbr_base(va_arg(ap, int), "01");
}

void my_print_pointer(char *arg, va_list ap, char *exceed, int index)
{
	if (exceed == NULL || (arg[index] != 'p' && arg[index] != 'P'))
		return;
	my_put_address((long long)va_arg(ap, long long));
}

void my_print_hexa(char *arg, va_list ap, char *exceed, int index)
{
	if (exceed == NULL || (arg[index] != 'x' && arg[index] != 'X'))
		return;
	int nbr = va_arg(ap, int);
	if (exceed[0] == '#')
		my_put_str("0x");
	my_putnbr_base(manage_param_space(nbr, exceed, 0), "0123456789ABCDEF");
	manage_param_space(nbr, exceed, 1);
}

void my_print_digit(char *arg, va_list ap, char *exceed, int index)
{
	int nbr;

	if (exceed == NULL || (arg[index] != 'd' && arg[index] != 'i'
		&& arg[index] != 'u'))
		return;
	nbr = va_arg(ap, int);
	my_put_nbr(manage_sign(arg, manage_param_space(nbr, exceed, 0)));
	manage_param_space(nbr, exceed, 1);
}