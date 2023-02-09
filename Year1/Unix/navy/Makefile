##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile
##

NAME		=		navy

INCLUDE		=		 -I include/ -I include/lib/

CFLAGS		+= 		-g -Wall -Wextra $(INCLUDE)

SRC			=		$(shell find . -type f -name '*.c')

LIB			=		libmy.a

OBJ			=		$(SRC:.c=.o)

RM			=		rm -f

LD_FLAGS	=		-L lib/my/


all:		$(NAME)

$(NAME):	$(OBJ)
			make -C lib/my
			gcc -o $(NAME) $(OBJ)  $(INCLUDE) $(LD_FLAGS)

debug:	    $(OBJ)
			make -C lib/my
			gcc -o $(NAME) $(OBJ) $(INCLUDE) $(LD_FLAGS)
clean:
			$(RM) $(OBJ)
			$(RM) $(NAME)
			$(RM) lib/libmy.a

fclean:		clean
			$(RM) $(NAME)

re:			fclean all