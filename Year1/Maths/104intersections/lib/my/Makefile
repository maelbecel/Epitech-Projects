##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile
##

NAME		=		libmy.a

MYH			=		my.h

CFLAGS 		=		-I ../../include

SRC			=		my_compute_power_rec.c				\
					my_compute_square_root.c			\
					my_find_prime_sup.c					\
					my_getnbr.c							\
					my_isneg.c							\
					my_is_prime.c						\
					my_putchar.c 						\
					my_put_nbr.c						\
					my_putstr.c							\
					my_revstr.c  						\
					my_showmem.c 						\
					my_showstr.c 						\
					my_show_word_array.c				\
					my_sort_int_array.c 				\
					my_strcapitalize.c 					\
					my_strcat.c 						\
					my_strcmp.c 						\
					my_strcpy.c 						\
					my_str_isalpha.c 					\
					my_str_islower.c 					\
					my_str_isnum.c 						\
					my_str_isprintable.c 				\
					my_str_isupper.c 					\
					my_strlen.c 						\
					my_strlowcase.c 					\
					my_strncat.c 						\
					my_strncmp.c 						\
					my_strncpy.c						\
					my_strstr.c 						\
					my_str_to_word_array.c 				\
					my_strupcase.c 						\
					my_swap.c							\
					my_strdup.c 						\
					inttochar.c							\
					my_printf.c				  \
					dispstr.c				  \
					dispchar.c				  \
					dispint.c				  \
					disppercent.c			  \
					dispunsigned.c			  \
					my_put_u_nbr.c			  \
					dispbin.c				  \
					my_put_nbr_base.c		  \
					dispoct.c				  \
					disphexa.c				  \
					disphexamaj.c			  \
					disppointer.c			  \

OBJ			=		$(SRC:.c=.o)

RM			=		rm -f

all:	$(NAME)

$(NAME):		$(OBJ)
				ar rc $(NAME) *.o
				cp $(NAME) ../
				## $(RM) $(OBJ)

clean:
			$(RM) $(NAME)
			$(RM) $(OBJ)

fclean:		clean
			$(RM) ../$(NAME)

re:		fclean all

.PHONY: all clean fclean re
