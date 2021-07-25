##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## compiles my libmy.a
##

SRC	=	my_putchar.c 	\
		my_put_nbr.c	\
		my_putstr.c	\
		my_strlen.c	\
		int_to_octal.c	\
		int_to_hexa_x.c	\
		int_to_hexa_maj.c	\
		tab_function.c	\
		int_to_bin.c	\
		adress.c	\
		unsigned_int.c	\
		pourcent.c	\
		my_printf.c	\
		my_strcmp.c	\
		my_str_to_word_array.c	\
		my_getnbr.c	\
		my_strcat.c	\
		my_strncmp.c	\
		my_strcpy.c	\
		my_strdup.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

INCLUDE	=	-I ./include

CFLAGS	=	-W -Wall -Wextra -g -Wno-unused-parameter

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
