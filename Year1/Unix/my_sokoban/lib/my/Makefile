##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile
##

NAME		=		libmy.a

MYH			=		my.h \
					printf.h \

SRC			=		concat.c \
					displaybinary.c \
					displaychar.c \
					displaynbr_dec.c \
					displaynbr_hexa_capital.c \
					displaynbr_hexa.c \
					displaynbr_octal.c \
					displaynbr.c \
					displaypercent.c \
					displaypointer.c \
					displaystr_unprintable.c \
					displaystr.c \
					inttochar.c \
					my_compute_power_rec.c \
					my_compute_square_root.c \
					my_find_prime_sup.c \
					my_getnbr.c \
					my_intlen.c \
					my_is_prime.c \
					my_isneg.c \
					my_printf.c \
					my_putstarstr.c \
					my_putstr.c \
					my_revstr.c \
					my_show_word_array.c \
					my_showmem.c \
					my_showstr.c \
					my_sort_int_array.c \
					my_str_isalpha.c \
					my_str_islower.c \
					my_str_isnum.c \
					my_str_isprintable.c \
					my_str_isupper.c \
					my_str_to_word_array.c \
					my_strcapitalize.c \
					my_strcat.c \
					my_strcmp.c \
					my_strcpy.c \
					my_strdup.c \
					my_strlen.c \
					my_strlowcase.c \
					my_strncat.c \
					my_strncmp.c \
					my_strncpy.c \
					my_strstr.c \
					my_strupcase.c \
					my_swap.c

CFLAGS      +=	    -I . -fvisibility=hidden

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
			@(ar rc $(NAME) *.o)
			@(mv $(NAME) ../)
			@(cp $(MYH) ../../include/)

clean:
			@($(RM) $(NAME))
			@($(RM) $(OBJ))
			@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE)" CLEAN "$(DEFAULT))

fclean:		clean
			@($(RM) ../$(NAME))
			@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE)" FCLEAN "$(DEFAULT))

re:		fclean all

debug:	CFLAGS += -g3 -pg
debug:	re
			@gcc -o $(NAME) $(OBJ) $(INCLUDE) $(LDFLAGS) \
			&& $(ECHO) $(BOLD) $(GREEN)"► BUILD SUCCESS !"$(DEFAULT) \
			|| ($(ECHO) $(BOLD) $(RED)"► BUILD FAILED"$(DEFAULT) && exit 1)

%.o:	%.c
			@gcc -c -o $@ $^ $(CFLAGS) && $(ECHO) -n $(BOLD) $(GREEN)"  [OK] " \
			$(WHITE) || $(ECHO) -n $(BOLD) $(RED)"  [KO] "$(WHITE) && $(ECHO) \
			$(BOLD) $< | rev | cut -d'/' -f 1 | rev && $(ECHO) -n $(DEFAULT)

.PHONY: all clean fclean re
