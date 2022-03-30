##
## EPITECH PROJECT, 2022
## sokoban [WSL: Manjaro]
## File description:
## Makefile
##

SRC	=	main.c	\
		src/maps.c	\
		src/check_help.c	\
		src/entities.c	\
		src/my_sokoban.c	\
		src/display.c	\
		src/movement.c	\
		src/condition.c	\
		src/map_info.c	\
		src/check_errors.c	\
		src/str_with_str.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban

CPPFLAGS	=	-I./include

LDFLAGS		= 	-L./lib/

LDLIBS		=	-lmy -lprintf

CFLAGS	=	-lncurses

all:	$(NAME)

lib:
	make -C ./lib/my
	make -C ./lib/printf

$(NAME):	lib $(OBJ)
	gcc $(CPPFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS) $(CFLAGS)

clean:
	rm -f $(OBJ)
	make -C ./lib/my clean
	make -C ./lib/printf clean

fclean: clean
	rm -f $(NAME)
	make -C ./lib/my fclean
	make -C ./lib/printf fclean

re:	fclean all

debug:	CFLAGS += -g
debug:	re

.PHONY: all lib clean fclean re debug
