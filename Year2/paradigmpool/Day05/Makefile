##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile
##

NAME		=		libstring.a

MYH			=		string.h

SRC			=		string.c \
					append.c \
					find.c   \
					split.c  \
					print.c  \
					compare.c

CFLAGS      +=         -I . -Wall -Wextra -pedantic -iquotes\
					   -Wstrict-prototypes \
					   -Wold-style-definition -fstack-protector -std=gnu17

OBJ			=		$(SRC:.c=.o)

RM			=		rm -f

ECHO		=		/bin/echo -e
DEFAULT		=		"\033[00m"
BOLD		=		"\e[1m"
RED			=		"\e[31m"
GREEN		=		"\e[32m"
LIGHT_BLUE	=		"\e[94m"
WHITE		=		"\e[1;37m"

all:	$(NAME)

$(NAME):		$(OBJ)
			@(ar rc $(NAME) $(OBJ))
			@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE) \
			"Lib 'string' sucessfully build. "$(DEFAULT))

clean:
			@($(RM) $(OBJ))
			@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE) \
			"Clean lib 'string' "$(DEFAULT))

fclean:		clean
			@($(RM) $(NAME))
			@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE) \
			"Fclean lib 'string' "$(DEFAULT))

re:		fclean all

debug:	CFLAGS += -g3 -pg
debug:	all
			@gcc -o $(NAME) $(OBJ) $(INCLUDE) $(LDFLAGS) \
			&& $(ECHO) $(BOLD) $(GREEN)"► BUILD SUCCESS !"$(DEFAULT) \
			|| ($(ECHO) $(BOLD) $(RED)"► BUILD FAILED"$(DEFAULT) && exit 1)

%.o:%.c
			@gcc -c -o $@ $< $(CFLAGS) -g

.PHONY: all clean fclean re debug
