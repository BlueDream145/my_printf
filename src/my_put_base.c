/*
** EPITECH PROJECT, 2017
** my_put_base.c
** File description:
**
*/

#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "../include/print.h"

int my_putnbr_base(int nbr, char const *base)
{
	int result = 0;
	int power = 1;
	int len_base = my_strlen(base);

	if (nbr == -1) {
		my_put_str("FFFFFFFF");
		return (0);
	}
	if (nbr < 0) {
		my_put_char('-');
		nbr = -nbr;
	}
	while ((nbr / power) >= len_base)
		power *= len_base;
	while (power > 0) {
		result = (nbr / power) % len_base;
		my_put_char(base[result]);
		power = power / len_base;
	}
	return (1);
}

int my_putnbr_base_long(long nbr, char *base)
{
	int i = 0;
	int size;
	long nb;

	if (nbr < 0) {
		nbr = - nbr;
		i += 1;
		my_put_char('-');
	}
	size = my_strlen(base);
	if (nbr > 0) {
		nb = nbr;
		nbr /= size;
		i += my_putnbr_base_long(nbr, base);
		i += 1;
		my_put_char(base[nb % size]);
	}
	return (i);
}

int my_put_special_base_str(char *str)
{
	int i = 0;

	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] >= 32 && str[i] <= 126)
			my_put_char(str[i]);
		else
			my_put_octal_format(convert_octal((int)str[i]));
	}
	return (0);
}

void my_put_octal_format(int octal)
{
	int count = 1;

	my_put_char('\\');
	while (octal * count < 100) {
		my_put_char('0');
		count *= 10;
	}
	my_put_nbr(octal);
}

void my_put_spaces(int requested_len, int nbr_len, int order)
{
	int i = 0;
	if (requested_len > 0 && order == 0)
		for (i = nbr_len; i < abs(requested_len); i++)
			my_put_char(' ');
	else if (requested_len < 0 && order == 1)
		for (i = nbr_len; i < abs(requested_len); i++)
			my_put_char(' ');
}