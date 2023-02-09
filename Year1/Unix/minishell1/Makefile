##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile for mysh
##

NAME         =		    mysh

INCLUDE      =         -I include/ -I include/lib/ -L lib/ -lmy

CFLAGS      +=         -Wall -Wextra -Werror $(INCLUDE)

SOURCES      =         src/

SRC          =         $(SOURCES)main.c \
					   $(SOURCES)environnement.c

LIB          =         libmy.a

OBJ          =	        $(SRC:.c=.o)

RM           =         rm -f

LD_FLAGS     =         -L lib/my/


all:         $(NAME)

$(NAME):	$(OBJ)
			make -C lib/my
			gcc -o $(NAME) $(OBJ)  $(INCLUDE) $(LD_FLAGS)

CFLAGS   +=  -g
debug:		$(OBJ)
			make -C lib/my
			gcc -o $(NAME) $(OBJ) $(INCLUDE) $(LD_FLAGS)

clean:
			make -C lib/my clean
			$(RM) $(OBJ)
			$(RM) lib/$(LIB)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all
