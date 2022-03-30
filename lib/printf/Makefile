##
## EPITECH PROJECT, 2022
## printf [WSL: Manjaro]
## File description:
## Makefile
##

HEADER = "printf.h"

SRC	=	my_putchar.c	\
		my_put_nbr.c	\
		my_putstr.c	\
		my_printf.c	\
		type.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libprintf.a

CPPFLAGS	=	-I.

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc -o $(NAME) $(OBJ)
	cp $(NAME) ../
	mkdir -p ../../include
	cp $(HEADER) ../../include/

clean :
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f ../$(NAME)
	rm -f ../../include/$(NAME)

re:	fclean all

.PHONY: all clean fclean re
