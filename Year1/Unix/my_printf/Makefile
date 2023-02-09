##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile
##

NAME		=		a.out

CFLAGS		= 		-I include/ -I include/lib/

LIB			=		libmy.a

RM			=		rm -f

all:		$(NAME)

$(NAME):
			make -C lib/my

test:
			make -C lib/my
			gcc tests/test_my_printf.c lib/my/*.c -L . -lmy -I . -Wall -Wextra
			./a.out

debug:
			make debug -C lib/my

fclean:
			$(RM) $(NAME)
			$(RM) lib/my/*.o

re:			fclean all
