##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile for doop
##

NAME         =		    doop

SOURCES      =         ./

SRC          =         $(SOURCES)main.hs


OBJ          =	        $(SRC:.c=.o)

TEMPFILES    =         *~ *vgcore* *.hi *.o tmplog

RM           =         rm -f


all:	$(NAME)

$(NAME):
			@ghc -o $(NAME) $(SRC)

clean:
			@$(RM) $(TEMPFILES)

fclean:		clean
			@$(RM) $(NAME)
			@$(RM) $(TEMPFILES)

re:
			@make fclean --no-print-directory
			@make --no-print-directory


.PHONY: all re clean fclean
