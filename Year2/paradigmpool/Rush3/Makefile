##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile for MyGKrellm
##

NAME         =		   MyGKrellm

INCLUDE      =         -I include/

SFML 		 = 		   -l sfml-graphics -l sfml-system -l sfml-window -l sfml-audio

CURST 		 = 		   -lncurses

CFLAGS       +=        -Wall -Wextra -std=c++2a $(INCLUDE)

SOURCES      =         src/

SRC          =         $(SOURCES)main.cpp 		\
					   $(SOURCES)Memory.cpp     \
					   $(SOURCES)Cpu.cpp        \
					   $(SOURCES)Info.cpp		\
					   $(SOURCES)Network.cpp	\
					   $(SOURCES)Weather.cpp	\
					   $(SOURCES)CURSES.cpp		\
					   $(SOURCES)SFML.cpp		\
					   $(SOURCES)ENGINE.cpp		\
					   $(SOURCES)Battery.cpp

TESTS        =         $(SOURCES)Memory.cpp     \
					   $(SOURCES)Cpu.cpp        \
					   $(SOURCES)Info.cpp		\
					   $(SOURCES)Network.cpp	\
					   $(SOURCES)Weather.cpp	\
					   $(SOURCES)Battery.cpp    \
					   tests/Cpu_tests.cpp      \
					   tests/Info_tests.cpp      \
					   tests/Weather_tests.cpp      \
					   tests/Memory_tests.cpp


SRC_COUNT    =         $(words $(SRC))

NB           =         0

TEMPFILES    =         unit_tests *~ *.gcda *.gcno *vgcore* *.html #*#

RM           =         rm -f

ECHO         =         /bin/echo -e
DEFAULT      =         "\033[00m"
BOLD         =         "\e[1m"
RED          =         "\e[31m"
GREEN        =         "\e[32m"
LIGHT_BLUE   =         "\e[94m"
WHITE        =         "\e[1;37m"

all:	$(NAME)

$(NAME):
			@echo
			@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE) \
			"SRC files sucessfully build. "$(DEFAULT))
			@g++ -o $(NAME) $(SRC) $(INCLUDE) $(SFML) $(CURST) $(CFLAGS) \
			&& $(ECHO) $(BOLD) $(GREEN)"\n► BUILD SUCCESS !"$(DEFAULT) \
			|| ($(ECHO) $(BOLD) $(RED)"\n► BUILD FAILED"$(DEFAULT) && exit 1)

debug:		CFLAGS += -g3
debug:		all

clean:
			@$(RM) $(TEMPFILES)
			@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE)" Clean SRC "$(DEFAULT))

fclean:		clean
			@$(RM) $(NAME)
			@$(RM) $(TEMPFILES)
			@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE)" Fclean SRC "$(DEFAULT))

tests_run:
			@g++ -o unit_tests $(TESTS) $(INCLUDE) $(SFML) $(CURST) $(CFLAGS) \
			-lcriterion --coverage
			@./unit_tests

docs:
			@doxygen Doxyfile
			xdg-open doc/html/index.html

coverage:	tests_run
			@gcovr --exclude tests/
			@gcovr --branches --exclude tests/
			@gcovr --exclude tests/ --html --html-details -o coverage.html

re:
			@make fclean --no-print-directory
			@make --no-print-directory

.PHONY: all re clean fclean debug
