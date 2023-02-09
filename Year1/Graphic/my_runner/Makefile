##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile
##

NAME		=		my_runner

INCLUDE		=		 -I include/ -I include/lib/

CFLAGS		+= 		-g -Wall -Wextra -Wswitch -Werror -Wimplicit-function-declaration -Wreturn-type $(INCLUDE)

SRC			=		$(shell find . -type f -name '*.c')

LIB			=		libmy.a

OBJ			=		$(SRC:.c=.o)

RM			=		rm -f

LD_FLAGS	=		-L lib/my/ -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio


all:		$(NAME)

$(NAME):	$(OBJ)
			make -C lib/my
			gcc -o $(NAME) $(OBJ) $(INCLUDE) $(LD_FLAGS)

debug:	    $(OBJ)
			make -C lib/my
			gcc -o $(NAME) $(OBJ) $(INCLUDE) $(LD_FLAGS)
clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)
			$(RM) lib/$(LIB)

re:			fclean all
