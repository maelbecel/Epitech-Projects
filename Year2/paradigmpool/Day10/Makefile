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

SRC          =         ABerry.cpp \
					   ACitrus.cpp \
					   AFruit.cpp \
					   Almond.cpp \
					   ANut.cpp \
					   BloodOrange.cpp \
					   Coconut.cpp \
					   FruitBox.cpp \
					   FruitFactory.cpp \
					   FruitMixer.cpp \
					   FruitUtils.cpp \
					   Grapefruit.cpp \
					   IFruit.cpp \
					   Lemon.cpp \
					   Orange.cpp \
					   Raspberry.cpp \
					   Strawberry.cpp

TESTS        =         tests/AFruit_test.cpp \
						tests/Fruitbox_test.cpp \
						tests/FruitFactory_test.cpp \
						tests/IFruits_test.cpp \
						tests/FruitUtils_test.cpp \
						tests/Fruit_test.cpp

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

tests_run:
			@g++ -o unit_tests $(SRC) $(TESTS) -lcriterion --coverage
			@./$(NAME)
fclean:		clean
			@$(RM) $(NAME) *.gcno *.gcda
			@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE)" Fclean SRC "$(DEFAULT))
coverage:
			@gcovr -r . --exclude tests/
			@gcovr -b --exclude tests/

.PHONY: all re clean fclean debug
