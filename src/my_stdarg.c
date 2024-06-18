/*
** EPITECH PROJECT, 2017
** my_stdarg.c
** File description:
**
*/

#include <stdarg.h>
#include "../include/print.h"

int sum_stdarg(int i, int nb, ...)
{
	va_list ap;
	int nbr = 0;
	int n = 0;

	va_start(ap, nb);
	if (i == 0)
		for (n = 0; n < nb; n++)
			nbr += va_arg(ap, int);
	else if (i == 1)
		for (n = 0; n < nb; n++)
			nbr += my_strlen((const char*)va_arg(ap, char*));
	va_end(ap);
	return (nbr);
}

int disp_stdarg(char *s, ...)
{
	int len = my_strlen(s);
	int i = 0;
	va_list ap;

	va_start(ap, s);
	for (i = 0; i < len; i++) {
		switch (s[i]) {
			case 'c':
				my_put_char(va_arg(ap, int));
				break;
			case 's':
				my_put_str(va_arg(ap, char*));
				break;
			case 'i':
				my_put_nbr(va_arg(ap, int));
				break;
		}
	}
	va_end(ap);
	return (0);
}