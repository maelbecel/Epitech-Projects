##$(shell find . -type f -name '*.c')
SRCC    =    $(shell find . -type f -name '*.c')

OBJ = $(shell find . -type f -name '*.o')

NAME    =    infin_add

all:    $(NAME)

$(NAME):	$(SRCC)
		gcc -g $(SRCC) -o $(NAME)

clean:
		rm -f $(OBJ)

fclean :
		rm -f $(NAME)
		rm -f $(OBJ)

re:		fclean all clean
