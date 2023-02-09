##$(shell find . -type f -name '*.c')
SRCC    =    $(shell find . -type f -name '*.c')

NAME    =    cat

all:    $(NAME)

$(NAME):	$(SRCC)
		gcc $(SRCC) -o $(NAME)

tests_run: $(SRCC)
		gcc -o unit_tests $(SRCC) ../tests/tests_$(NAME).c --coverage -lcriterion
		./unit_tests

clean:
		rm -f $(OBJ)

fclean :
		rm -f $(NAME)
		rm -f $(OBJ)

re:		fclean all clean
