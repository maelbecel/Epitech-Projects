##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile for tetris
##

NAME         =		    tetris

INCLUDE      =         	-I include/ -I include/lib/ -L lib/ -lmy -lmyprintf \
						-lncurses

CFLAGS      +=         	-Wall -Wextra -Werror -fvisibility=hidden $(INCLUDE)

SOURCES      =         	src/

SRC          =         	$(SOURCES)tetris.c   				\
						$(SOURCES)init.c     				\
						$(SOURCES)draw.c     				\
						$(SOURCES)letters.c  				\
						$(SOURCES)verif.c	  				\
						$(SOURCES)display.c					\
						$(SOURCES)option.c					\
						$(SOURCES)debug.c					\
						$(SOURCES)tetrimino.c				\
						$(SOURCES)my_str_to_word_array.c   	\
						$(SOURCES)display_tet.c

SRC_COUNT    =         	$(words $(SRC))

NB           =         	0

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

all:	$(NAME)

$(NAME):	$(OBJ)
			@echo
			@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE) \
			"SRC files sucessfully build. "$(DEFAULT))
			@make -C lib/my/ --no-print-directory
			@make -C lib/myprintf/ --no-print-directory
			@gcc -o $(NAME) $(OBJ) $(INCLUDE) \
			&& $(ECHO) $(BOLD) $(GREEN)"\n► BUILD SUCCESS !"$(DEFAULT) \
			|| ($(ECHO) $(BOLD) $(RED)"\n► BUILD FAILED"$(DEFAULT) && exit 1)

debug:		CFLAGS += -g3 -pg
debug:		all

clean:
			@make -C lib/my/ clean --no-print-directory
			@make -C lib/myprintf/ clean --no-print-directory
			@$(RM) $(OBJ)
			@$(RM) $(TEMPFILES)
			@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE)" Clean SRC "$(DEFAULT))

fclean:		clean
			@make -C lib/myprintf/ fclean --no-print-directory
			@make -C lib/my/ fclean --no-print-directory
			@$(RM) $(NAME)
			@$(RM) $(OBJ)
			@$(RM) $(TEMPFILES)
			@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE)" Fclean SRC "$(DEFAULT))

re:
			@make fclean --no-print-directory
			@make --no-print-directory

%.o:		%.c
			@$(eval NB=$(shell echo $$(($(NB)+1))))
			@gcc -c -o $@ $^ $(CFLAGS) && python build/build.py $< $(NB) \
			$(SRC_COUNT)

.PHONY: all re clean fclean debug
