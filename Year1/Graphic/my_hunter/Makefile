##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile
##

NAME		=		my_hunter

INCLUDE		=		 -I include/ -I include/lib/

CFLAGS		+= 		-Wall -Wextra -Wswitch -Wimplicit-function-declaration -Wreturn-type $(INCLUDE)

SRC			=		$(shell find . -type f -name '*.c')

LIB			=		libmy.a

OBJ			=		$(SRC:.c=.o)

RM			=		rm -f

LD_FLAGS	=		-L lib/my/ -lmy -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio


all:		$(NAME)

$(NAME):	$(OBJ)
			make -C lib/my
			gcc -o $(NAME) $(OBJ)  $(INCLUDE) $(LD_FLAGS)

debug:	    $(OBJ)
			make -C lib/my
			gcc -g -o $(NAME) $(OBJ) $(INCLUDE) $(LD_FLAGS)
clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all
