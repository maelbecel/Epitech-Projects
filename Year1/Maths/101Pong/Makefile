##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile
##

NAME		=		101pong

CFLAGS		+= 		-Wall -Wextra -I include/ -I include/lib/

SRC			=		pong.c	   	      \
					calcul_velocity.c \
					calcul_coordinates.c \
					calcul_angle.c \
					my_strlen.c\

OBJ			=		$(SRC:.c=.o)

RM			=		rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
			gcc -o $(NAME) $(OBJ) -I include/ -lm
			$(RM) $(OBJ)

debug:	    $(OBJ)
			gcc -g -o $(NAME) $(OBJ) -I include/

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all
