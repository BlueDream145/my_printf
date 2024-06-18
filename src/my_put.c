/*
** EPITECH PROJECT, 2017
** my_put.c
** File description:
**
*/

#include <unistd.h>
#include "../include/print.h"

void my_put_char(char c)
{
	write(1, &c, 1);
}

int my_put_str(char const *str)
{
	int length = 0;

	while (str[length] != '\0') {
		my_put_char(str[length]);
		length++;
	}
	return (0);
}

int my_put_nbr(int nb)
{
	int arr[999];
	int i = 0;
	int len = number_digits(nb);

	if (nb < 0) {
		my_put_char('-');
		nb = nb *-1;
	}
	for (i = 0; i < len; i++) {
		arr[i] = nb % 10;
		nb /= 10;
	}
	for (int b = i - 1; b > -1; b--)
		my_put_char(arr[b] + '0');
	return (0);
}

int my_put_float(double nbr)
{
	long dec;
	long ent;
	double dec2;
	int i = 0;

	ent = nbr;
	dec = nbr * (float)1000000;
	dec -= ent * 1000000;
	dec2 = (double)dec;
	i += my_putnbr_base_long(ent, "0123456789");
	i++;
	my_put_char('.');
	i += my_putnbr_base_long((long)dec2, "0123456789");
	return (i);
}

int my_put_address(long long nbr)
{
	int i = 0;

	if ((void*)nbr == NULL)
		i += my_put_str("(nil)");
	else {
		i += my_put_str("0x");
		i += my_putnbr_base_long(nbr, "0123456789abcdef");
	}
	return (i);
}