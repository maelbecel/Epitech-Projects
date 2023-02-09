NAME	=    do-op

CC	  =    gcc

SRC	   =    do_op.c

OBJ	   =    $(SRC:.c=.o)

FLAG	   =    -L ../lib/my/ -lmy

all: $(NAME)

$(NAME):
		$(CC) $(SRC) -o $(NAME) $(FLAG)

clean:
		rm -f $(OBJS)

fclean: 
		rm -f $(OBJS)
		rm -f $(NAME)

re: fclean all