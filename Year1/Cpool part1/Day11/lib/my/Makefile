SRCC    =    $(shell find . -type f -name '*.c')

OBJ    =	$(SRCC:.c=.o)

INFO    =    "Sucess."

NAME    =    libmy.a

H = my.h

FLAGS=	-W -Wall -Wextra -pedantic -ansi

all:    $(NAME)

$(NAME):    $(OBJ)
		    gcc -c $(SRCC)
		    ar -rv $(NAME) $(OBJ)
		    cp  $(NAME) ../$(NAME)
		    cp $(H) ../../include/$(H)
		    echo $(INFO)


clean:
		rm -f $(OBJ)

fclean :
		rm -f $(OBJ)
		rm -f $(NAME)


re:		fclean all clean
