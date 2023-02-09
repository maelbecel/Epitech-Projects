##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC     =       $(bash find -name *.c)

OBJ     =       $(SRC:.c=.o)

NAME    =       eval_expr

all:    $(NAME)

$(NAME):        $(SRC)
	gcc *.c -I include/ -o $(NAME)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)

re:     fclean all

debug:
	gcc *.c -g -Wall -Wextra -I include/ -o $(NAME)
