##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile
##

NAME		=		104intersection

CFLAGS		= 		-g3 -Wall -Wextra -I include/ -lm

SRC			=		src/main.c			\
					src/sphere.c 		\
					src/cylinder.c 		\
					src/cone.c 			\
					src/calcul.c

OBJ			=		$(SRC:.c=.o)

RM			=		rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
			make -C lib/my
			gcc -o $(NAME) $(OBJ) -I include/ -L lib/ -lmy -lm
			## $(RM) $(OBJ)

debug:	    $(OBJ)
			make -C lib/my
			gcc -o $(NAME) $(OBJ) -I include/ -L lib/ -lmy

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all
