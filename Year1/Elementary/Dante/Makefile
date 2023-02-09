##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile for dante
##

all:	$(OBJ)
			@make -C ./solver/ --no-print-directory
			@make -C ./generator/ --no-print-directory

debug:
			@make -C ./solver/ debug --no-print-directory
			@make -C ./generator/ debug --no-print-directory


clean:
			@make -C ./solver/ clean --no-print-directory
			@make -C ./generator/ clean --no-print-directory


fclean:		clean
			@make -C ./solver/ fclean --no-print-directory
			@make -C ./generator/ fclean --no-print-directory


re:
			@make -C ./solver/ re --no-print-directory
			@make -C ./generator/ re --no-print-directory


.PHONY: all re clean fclean debug
