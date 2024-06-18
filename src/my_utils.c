/*
** EPITECH PROJECT, 2017
** my_utils.c
** File description:
**
*/

#include "../include/print.h"

int my_strlen(char const *str)
{
	int count = 0;

	while (str[count] != '\0')
		count++;
	return (count);
}

int number_digits(int nbr)
{
	int n = 1;
	int po = 10;

	if (nbr < 0)
		nbr = -nbr;
	while (nbr >= po) {
		n++;
		if (po > 214748364)
			break;
		po *= 10;
	}
	return (n);
}

void delete_char(char *str, int i)
{
	int len = my_strlen(str);

	for (; i < len - 1; i++) {
		str[i] = str[i+1];
	}
	str[i] = '\0';
}

double manage_sign(char *exceed, double nbr)
{
	int signe = 0;
	int i = 0;

	for (i = 0; exceed[i] != '\0'; i++) {
		if (signe == 0 && exceed[i] == '+')
			signe = 1;
		if (exceed[i] == '-')
			signe *= -1;
		else if (exceed[i] == '+')
			signe *= 1;
		}
	if (nbr > 0 && signe == 1)
		my_put_char('+');
	return (nbr);
}