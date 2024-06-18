/*
** EPITECH PROJECT, 2017
** manage_param.c
** File description:
**
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "../include/print.h"

int manage_param(char *arg, va_list ap)
{
	int len = my_strlen(arg);
	int index = 1;
	int i = 0;
	char *exceed = malloc(sizeof(char) * len - 1);

	if(exceed == NULL)
		exit(84);
	if (len > 2 && (arg[1] == '#' || arg[1] == '+' || arg[1] == '-'
	|| arg[1] == ' ' || (arg[1] <= '9' && arg[1] >= '0'))) {
		index = len - 1;
		for (i = 1; i < len - 1; i++)
			exceed[i - 1] = arg[i];
	}
	if (len != 0) {
		if (exceed[0] == ' ' && !(exceed[1] >= '0' && exceed[1] <= '9'))
			my_put_char(' ');
		if (dispatch_param(arg, ap, index, exceed) == 1)
			return (1);
	}
	return (0);
}

int dispatch_param(char *arg, va_list ap, int index, char *exceed)
{
	if (arg[index] == 'l' && arg[index + 1] == 'x')
		index++;
	if (print_entries[(int)arg[index]] != NULL) {
		print_entries[(int)arg[index]](arg, ap, exceed, index);
		return (1);
	}
	return (0);
}

int manage_param_space(int nbr, char *exceed, int order)
{
	int requested_len = my_getnbr(exceed);
	int nbr_len = number_digits(nbr);
	int exceed_len = my_strlen(exceed);

	if (nbr < 0 || (exceed[exceed_len - 1] == '+' ||
	exceed[exceed_len - 1] == '-'))
		nbr_len++;
	if (requested_len != 0)
		my_put_spaces(requested_len, nbr_len, order);
	return (nbr);
}