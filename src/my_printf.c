/*
** EPITECH PROJECT, 2017
** my_printf.c
** File description:
**
*/

#include <stdio.h>
#include <stdarg.h>
#include "../include/print.h"

int my_param(char *str, va_list ap, int index)
{
	char *arg;

	arg = get_param(str, index);
	if (manage_param(arg, ap) == 1)
		index += my_strlen(arg) - 1;
	else
		my_put_char(str[index]);
	return (index);
}

void my_printf(char *str, ...)
{
	va_list ap;
	int i = 0;

	my_print_dictionary();
	va_start(ap, str);
	for (i = 0; str[i] != '\0'; i++)
		if (str[i] == '%')
			i = my_param(str, ap, i);
		else
			my_put_char(str[i]);
	va_end(ap);
}

void my_print_dictionary(void)
{
	print_entries[(int)('s')] = my_print_string;
	print_entries[(int)('c')] = my_print_char;
	print_entries[(int)('S')] = my_print_special_string;
	print_entries[(int)('o')] = my_print_octal;
	print_entries[(int)('e')] = my_print_scientific;
	print_entries[(int)('E')] = my_print_scientific;
	print_entries[(int)('f')] = my_print_float;
	print_entries[(int)('F')] = my_print_float;
	print_entries[(int)('b')] = my_print_binary;
	print_entries[(int)('B')] = my_print_binary;
	print_entries[(int)('p')] = my_print_pointer;
	print_entries[(int)('P')] = my_print_pointer;
	print_entries[(int)('x')] = my_print_hexa;
	print_entries[(int)('X')] = my_print_hexa;
	print_entries[(int)('d')] = my_print_digit;
	print_entries[(int)('i')] = my_print_digit;
	print_entries[(int)('u')] = my_print_digit;
	print_entries[(int)('%')] = my_print_modulo;
}