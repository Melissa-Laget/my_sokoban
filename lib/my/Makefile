##
## EPITECH PROJECT, 2022
## lib [WSL: Manjaro]
## File description:
## Makefile
##

SRC	=	my_strlen.c	\
		my_getnbr.c	\
 		my_strcmp.c	\
		my_putchar.c	\
		my_strdup.c	\
		my_str_to_word_array.c	\
		my_put_nbr.c	\
		my_putstr.c	\
		my_nbrlen.c	\
		concat_str.c	\
		add_to_char_arr.c	\
		char_arr_len.c	\
		free_char_arr.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mkdir -p ../../include
	cp my.h ../../include
	cp $(NAME) ../

clean :
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re:	fclean all
