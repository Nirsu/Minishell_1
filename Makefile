##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

NAME	=	mysh

SRC	=	src/my_putstr.c		\
		src/my_putchar.c	\
		src/my_strlen.c		\
		src/compare_str.c	\
		src/my_get_next_line.c	\
		src/my_str_to_wordtab.c	\
		src/my_str_concast.c	\
		main.c			\
		recup_env.c		\
		exec_command.c		\
		epu_str.c		\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I ./include

CPPFLAGS +=	-W -Wall -Wextra

all:	$(NAME)

$(NAME): $(OBJ)
	gcc $(CFLAGS) -o $(NAME) $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
