/*
** EPITECH PROJECT, 2017
** print.h
** File description:
**
*/

#include <stdarg.h>

int convert_octal(int dec);
void convert_scientific(double dec, int maj);
char *convert_lower(char *str);
char *get_param(char *str, int start);
int my_getnbr(char *str);
int get_syntax(char c);
int manage_param(char *arg, va_list ap);
void my_printf(char *str, ...);
int my_param(char *str, va_list ap, int index);
int my_putnbr_base(int nbr, char const *base);
int my_putnbr_base_long(long nbr, char *base);
int my_put_special_base_str(char *str);
void my_put_spaces(int requested_len, int nbr_len, int order);
void my_put_octal_format(int octal);
void my_put_char(char c);
int my_put_str(char const *str);
int my_put_nbr(int nb);
int my_put_float(double nbr);
int my_put_address(long long nbr);
int my_strlen(char const *str);
int number_digits(int nbr);
void delete_char(char *str, int i);
double manage_sign(char *exceed, double nbr);
int manage_param_space(int nbr, char *exceed, int order);
int sum_stdarg(int i, int nb, ...);
int disp_stdarg(char *s, ...);
void my_print_dictionary(void);
int dispatch_param(char *arg, va_list ap, int index, char *exceed);
void my_print_string(char *arg, va_list ap, char *exceed, int index);
void my_print_char(char *arg, va_list ap, char *exceed, int index);
void my_print_special_string(char *arg, va_list ap, char *exceed, int index);
void my_print_octal(char *arg, va_list ap, char *exceed, int index);
void my_print_scientific(char *arg, va_list ap, char *exceed, int index);
void my_print_float(char *arg, va_list ap, char *exceed, int index);
void my_print_binary(char *arg, va_list ap, char *exceed, int index);
void my_print_pointer(char *arg, va_list ap, char *exceed, int index);
void my_print_hexa(char *arg, va_list ap, char *exceed, int index);
void my_print_digit(char *arg, va_list ap, char *exceed, int index);
void my_print_modulo(char *arg, va_list ap, char *exceed, int index);

void (*print_entries[172])(char *arg, va_list ap, char *exceed, int index);