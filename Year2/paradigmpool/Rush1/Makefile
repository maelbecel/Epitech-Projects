##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile for pushswap checker
##

NAME         =		   pushswap_checker

SOURCES      =         src/

SRC          =         $(SOURCES)Main.hs \
					   $(SOURCES)Action.hs \


TEMPFILES    =         *~ *vgcore* *.hi src/*.o tmplog src/*.hi

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
