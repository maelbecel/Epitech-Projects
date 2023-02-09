##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile
##

NAME		=		libparser.a

MYH			=		parser.h

SRC			=		html/get_balise_content.c \
					html/get_balise_from_place.c \
					html/get_content_by_id.c \
					html/get_content_by_class.c \
					json/coat.c \
					json/fill_file.c \
					json/get_line_pars.c \
					json/get_value.c \
					json/get_update.c \
					json/int_array_from_json.c \
					json/int_from_json.c \
					json/parser.c \
					json/str_from_json.c \
					json/str_array_from_json.c \
					json/update_file.c


CFLAGS      +=         -I . -Wall -Wextra -pedantic \
					   -Wstrict-prototypes \
					   -Wold-style-definition -fstack-protector -std=c99

OBJ			=		$(SRC:.c=.o)

SRC_COUNT    :=         $(words $(SRC))

NB           =         0

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
			@(mv $(NAME) ../)
			@(cp $(MYH) ../../include/)
			@($(ECHO) " ")
			@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE) \
			"Lib 'parser' sucessfully build. "$(DEFAULT))

clean:
			@($(RM) $(NAME))
			@($(RM) $(OBJ))
			@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE) \
			"Clean lib 'parser'"$(DEFAULT))

fclean:		clean
			@($(RM) ../$(NAME))
			@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE) \
			"Fclean lib 'parser'"$(DEFAULT))

re:		fclean all

debug:	CFLAGS += -g3 -pg
debug:	re
			@gcc -o $(NAME) $(OBJ) $(INCLUDE) $(LDFLAGS) \
			&& $(ECHO) $(BOLD) $(GREEN)"► BUILD SUCCESS !"$(DEFAULT) \
			|| ($(ECHO) $(BOLD) $(RED)"► BUILD FAILED"$(DEFAULT) && exit 1)

%.o:		%.c
			@$(eval NB=$(shell echo $$(($(NB)+1))))
			@gcc -c -o $@ $^ $(CFLAGS) \
			&& python3 ../../build/build.py $< $(NB) $(SRC_COUNT)

.PHONY: all clean fclean re
