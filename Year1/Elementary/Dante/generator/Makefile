##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile for dante
##

ECHO = /bin/echo -e
DEFAULT = "\033[00m"
BOLD = " "
RED = "\e[31m"
GREEN = "\e[32m"
LIGHT_BLUE = "\e[94m"
WHITE = " "

SOURCES      =         src/

SRC          =         	$(SOURCES)main.c        \
						$(SOURCES)init.c 		\
						$(SOURCES)imperfect.c   \
						$(SOURCES)generator.c	\

OBJ		=	$(SRC:.c=.o)

NAME	=	generator

INCLUDE = -I./include

LIB = -L ../lib/ -l my -l myprintf

CFLAGS 	 = -I ../include -Wall -Wextra

LDFLAGS += -I ../include $(LIB)

SRC_COUNT := $(words $(SRC))
NB = 0

$(NAME): $(OBJ) build_lib
		@$(CC) $(OBJ) -o $(NAME) $(LDFLAGS) \
		&& $(ECHO) $(BOLD) $(GREEN)"\n► BUILD SUCCESS !"$(DEFAULT) \
		|| ($(ECHO) $(BOLD) $(RED)"\n► BUILD FAILED"$(DEFAULT) && exit 1)

all: $(NAME)

build_lib:
		@$(ECHO)
		@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE) \
		"generator files sucessfully build. "$(DEFAULT))
		@make -C ../lib/my --no-print-directory
		@make -C ../lib/myprintf --no-print-directory

clean:
		@$(RM) -f $(OBJ)
		@make clean -C ../lib/my --no-print-directory
		@make clean -C ../lib/myprintf --no-print-directory
		@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE)" CLEAN "$(DEFAULT))

fclean: clean
		@$(RM) -f $(NAME)
		@make fclean -C ../lib/my --no-print-directory
		@make fclean -C ../lib/myprintf --no-print-directory
		@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE)" FCLEAN "$(DEFAULT))

re: fclean all

debug: CFLAGS += -g
debug: re

%.o: %.c
		@gcc -c -o $@ $^ $(CFLAGS) && $(ECHO) -n $(BOLD) $(GREEN)"  [OK] "
		$(WHITE) || $(ECHO) -n $(BOLD) $(RED)"  [KO] "$(WHITE) && $(ECHO)
		$(BOLD) $< | rev | cut -d'/' -f 1 | rev

.PHONY: all re clean fclean debug build_lib %.o