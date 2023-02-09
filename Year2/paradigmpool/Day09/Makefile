##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile for unit_tests
##

NAME         =		    unit_tests

CXXFLAGS       +=         -Wall -Wextra -pedantic \
					        -Wstrict-prototypes -fstack-protector\
					        -Wold-style-definition

SRC          =         Enchanter.cpp \
					   HealthPotion.cpp \
					   Knight.cpp \
					   Paladin.cpp \
					   Peasant.cpp \
					   PoisonPotion.cpp \
					   PowerPotion.cpp \
					   Priest.cpp

TESTS        =         tests/Peasant_test.cpp \
					   tests/Knight_test.cpp \
					   tests/Paladin_test.cpp \
					   tests/Enchanter_test.cpp

NB           =         0

OBJ          =	        $(SRC:.c=.o)

TEMPFILES    =         *~ *vgcore* #*#

RM           =         rm -f

ECHO         =         /bin/echo -e
DEFAULT      =         "\033[00m"
BOLD         =         "\e[1m"
RED          =         "\e[31m"
GREEN        =         "\e[32m"
LIGHT_BLUE   =         "\e[94m"
WHITE        =         "\e[1;37m"

fclean:		clean
			@$(RM) $(NAME) *.gcno *.gcda
			@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE)" Fclean SRC "$(DEFAULT))
tests_run:
			@g++ -o unit_tests $(SRC) $(TESTS) -lcriterion --coverage
			@./$(NAME)
coverage:
			@gcovr -r . --exclude tests/
			@gcovr -b --exclude tests/

.PHONY: all re clean fclean debug
