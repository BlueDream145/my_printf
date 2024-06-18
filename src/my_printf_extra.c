/*
** EPITECH PROJECT, 2017
** my_printf_extra.c
** File description:
**
*/

#include <stdlib.h>
#include <stdarg.h>
#include "../include/print.h"

void my_print_modulo(char *arg, va_list ap, char *exceed, int index)
{
	if (exceed == NULL || ap == NULL || arg[index] != '%')
		return;
	my_put_char('%');
}