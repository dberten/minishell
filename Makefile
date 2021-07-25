##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## compiles my libmy.a
##

SRC	=	src/minishell1/main.c	\
		src/minishell1/loop.c	\
		src/minishell1/my_setenv.c	\
		src/minishell1/my_setenv_2.c	\
		src/minishell1/my_ensetenv.c	\
		src/minishell1/system_function.c	\
		src/minishell1/exec_path.c	\
		src/minishell1/my_cd.c	\
		src/minishell1/too_long.c	\
		src/minishell1/my_env.c	\
		src/semicolon/my_semicolon.c	\
		src/minishell1/clean_str.c	\
		src/redirection/redirection.c	\
		src/redirection/set_up_redirection.c	\
		src/redirection/set_up_redirection_2.c	\
		src/minishell1/stock_path.c	\
		src/redirection/string.c	\
		src/minishell1/my_exec.c	\
		src/minishell1/all_function.c	\
		src/redirection/fill_tab_redirect.c	\
		src/redirection/mult_redirection.c	\
		src/pipe/pipe.c	\
		src/minishell1/all_function_2.c	\
		src/pipe/error_pipe.c

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

CFLAGS	=	-W -Wall -Wextra -g -Wno-unused-parameter -I ./include -L ./lib/my -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) -L ./lib/my -lmy

valgrind:
	gcc -o $(NAME) $(SRC) -L ./lib/my -lmy -I ./include
	valgrind --leak-check=full --track-origins=yes ./$(NAME)

clean:
	make clean -C lib/my
	rm -f $(OBJ)

fclean: clean
	make fclean -C lib/my
	rm -f $(NAME)

re:	fclean all
