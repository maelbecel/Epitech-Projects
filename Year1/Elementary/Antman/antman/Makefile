##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile
##

NAME		=		antman

INCLUDE		=		 -I include/ -I include/lib/ -L lib/ -lmy

CFLAGS		+= 		-Wall -Wextra $(INCLUDE) -g

SRC			=		src/antmain.c		\
					src/img.c			\
					src/html.c          \
					src/txt.c           \
					src/str_to_word_array.c

LIB			=		libmy.a

OBJ			=		$(SRC:.c=.o)

RM			=		rm -f

LD_FLAGS	=		-L lib/my/


all:		$(NAME)

$(NAME):	$(OBJ)
			make -C lib/my
			gcc -o $(NAME) $(OBJ)  $(INCLUDE) $(LD_FLAGS)

debug:	    $(OBJ)
			make -C lib/my
			gcc -o $(NAME) $(OBJ) $(INCLUDE) $(LD_FLAGS)
clean:
			$(RM) $(OBJ)
			$(RM) lib/$(LIB)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all
