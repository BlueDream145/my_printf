/*
** EPITECH PROJECT, 2017
** my_convert.c
** File description:
**
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/print.h"

char *convert_lower(char *str)
{
	int i = 0;

	for (; str[i] != '\0'; i++)
		if (str[i] <= 'Z' && str[i] >= 'A')
			str[i] += 32;
	return (str);
}

int convert_octal(int dec)
{
	int octal = 0;
	int i = 1;

	while (dec != 0) {
		octal += (dec % 8) * i;
		dec /= 8;
		i *= 10;
	}
	return (octal);
}

void convert_scientific(double dec, int maj)
{
	int i = 0;

	while (!(dec < 10 && dec > -10)) {
		dec /= 10;
		i++;
	}
	my_put_float(dec);
	if (maj == 1)
		my_put_char('E');
	else
		my_put_char('e');
	my_put_char('+');
	if (number_digits(i) < 2)
		my_put_char('0');
	my_put_nbr(i);
}