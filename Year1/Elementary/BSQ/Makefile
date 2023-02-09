##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile
##

NAME		=		bsq

CFLAGS		= 		-Wall -Wextra -I include/ -I include/lib/

SRC			=		$(shell find . -type f -name '*.c')

LIB			=		libmy.a

OBJ			=		$(SRC:.c=.o)

RM			=		rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
			make -C lib/my
			gcc -o $(NAME) $(OBJ) -I include/ -L lib/my/ -lmy
			$(RM) $(OBJ)
			$(RM) lib/$(LIB)
			$(RM) lib/my/$(LIB)

debug:	    CFLAGS += -g
debug:	    $(OBJ)
			make -C lib/my
			gcc -o $(NAME) $(OBJ) -I include/ -L lib/my/ -lmy
			$(RM) $(OBJ)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all
