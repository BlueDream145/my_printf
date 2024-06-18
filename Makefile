##
## EPITECH PROJECT, 2017
## Makefile
## File description:
##
##

SRC	=	src/my_convert.c \
		src/my_param.c \
		src/my_printf.c \
		src/my_printf_basics.c \
		src/my_printf_decimal.c \
		src/my_printf_extra.c \
		src/my_put_base.c \
		src/my_put.c \
		src/my_stdarg.c \
		src/my_utils.c \
		src/my_get.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C tests
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	clean fclean re all
