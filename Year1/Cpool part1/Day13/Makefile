##$(shell find . -type f -name '*.c')
SRCC    =    $(shell find . -type f -name '*.c')

NAME    =    window

all:    $(NAME)

$(NAME):	$(SRCC)
		gcc $(SRCC) -o $(NAME) -lcsfml-graphics -lcsfml-window -lcsfml-system

tests_run: $(SRCC)
		gcc -o unit_tests $(SRCC) ../tests/tests_$(NAME).c --coverage -lcriterion
		./unit_tests

clean:
		rm -f $(OBJ)

fclean :
		rm -f $(NAME)

re:		fclean all clean
