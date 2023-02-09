##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile
##

NAME		=		libmy.a

MYH			=		printf.h \
					my.h \

SRC			=		$(shell find . -type f -name '*.c')

CFLAGS      +=	    -I .

OBJ			=		$(SRC:.c=.o)

RM			=		rm -f

all:	$(NAME)

$(NAME):		$(OBJ)
				ar rc $(NAME) $(OBJ)
				mv $(NAME) ../../
				cp $(MYH) ../../
				cp $(MYH) ../

clean:
			$(RM) $(NAME)
			$(RM) $(OBJ)

fclean:		clean
			$(RM) ../$(NAME)

re:		fclean all

debug:	CFLAGS += -g
debug:	re

.PHONY: all clean fclean re
