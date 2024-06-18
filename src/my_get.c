/*
** EPITECH PROJECT, 2017
** my_get.c
** File description:
**
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/print.h"

int my_getnbr(char *str)
{
	int i = 0;
	int n = 0;
	int signe = 1;

	for(i = 0; str[i] != '\0'; i++) {
		if ((str[i] == '-' && signe == -1 && n == 0) ||
		(str[i] == '+' && n == 0))
			signe = 1;
		else if (str[i] == '-' && n == 0)
			signe = -1;
		if ((str[i] < '0' || str[i] > '9') && n > 0)
			break;
		else if ((str[i] < '0' || str[i] > '9') && n == 0)
			continue;
		n = n + str[i] - 48;
		n = n * 10;
	}
	n /= 10;
	return (n * signe);
}

char *get_param(char *str, int start)
{
	int i = start;
	int count = 0;
	char *result;

	result = malloc(sizeof(char) * 4);
	for (; str[i] != '\0'; i++) {
		if (count <= 1 && (str[i] == '%' || str[i] == ' ')) {
			result[count] = str[i];
			count++;
			continue;
		}
		if (count > 0 && get_syntax(str[i]) == 1) {
			result[count] = str[i];
			count++;
		} else if (count > 0)
			return (result);
	}
	return (result);
}

int get_syntax(char c)
{
	char allowed_chars[32] = "pcBbEeXlxFfSsdiuo0123456789#+-.";
	int i = 0;

	for (i = 0; i < 32; i++)
		if(allowed_chars[i] == c)
			return (1);
	return (0);
}