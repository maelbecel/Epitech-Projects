##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile
##

NAME		=		103cipher

CFLAGS		= 		-g3 -Wall -Wextra -I include/ -lm

SRC			=		src/main.c				\
					src/key.c				\
					src/msg.c               \
					src/matrice.c           \

LIB			=		libmy.a

OBJ			=		$(SRC:.c=.o)

RM			=		rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
			make -C lib/my
			gcc -o $(NAME) $(OBJ) $(CFLAGS)

debug:	    $(OBJ)
			make -C lib/my
			gcc -o $(NAME) $(OBJ) -I include/ -L lib/my/ -lmy

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all
