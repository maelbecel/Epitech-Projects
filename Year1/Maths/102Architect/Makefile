##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile
##

NAME		=		102architect

CFLAGS		= 		-g3 -Wall -Wextra -I include/

SRC			=		src/create_identity.c 			\
					src/create_matrix.c 			\
					src/main.c 						\
					src/print_action.c 				\
					src/vector_to_matrix.c			\
					src/matrice3x3.c				\
					src/create_matrice3x1.c			\
					src/matrix3x1.c

LIB			=		libmy.a

OBJ			=		$(SRC:.c=.o)

RM			=		rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
			make -C lib/my
			gcc -o $(NAME) $(OBJ) -lm -I include/ -L lib/my/ -lmy
			## $(RM) $(OBJ)

debug:	    $(OBJ)
			make -C lib/my
			gcc -o $(NAME) $(OBJ) -I include/ -L lib/my/ -lmy

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all
