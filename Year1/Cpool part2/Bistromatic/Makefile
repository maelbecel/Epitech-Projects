##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile
##

NAME		=		calc

CFLAGS		+= 		-Wall -Wextra -I include/ -I include/lib/

SRC			=		src/launch.c	   	   \
					src/error.c        \
					src/infin_add.c    \
					src/infin_sub.c    \
					src/infin_mul.c    \
					src/infin_mod.c    \
					src/infin_div.c    \
					src/detection.c    \
					src/operator.c     \
					src/removez.c      \
					src/errorbase.c    \
					src/get_expr.c     \
					src/eval_expr.c    \
					src/classic_op.c   \
					src/usage.c        \
					src/nbnumber.c     \

LIB			=		libmy.a

OBJ			=		$(SRC:.c=.o)

RM			=		rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
			make -C lib/my
			gcc -o $(NAME) $(OBJ) -I include/ -L lib/my/ -lmy
			$(RM) $(OBJ)

debug:	    $(OBJ)
			make -C lib/my
			gcc -g -o $(NAME) $(OBJ) -I include/ -L lib/my/ -lmy

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all
