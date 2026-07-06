##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

SRC =		src/main.c										\

OBJ = $(SRC:.c=.o)

CC = epiclang

CFLAGS += -Wall -Wextra -I./include

NAME = my_top

all: $(NAME)

$(NAME): $(OBJ)
	@echo "✧ COMPILING PROGRAM ✧"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -g -lncurses
	@echo "✧ DONE ✧"

%.o:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "✧ REMOVING .o ✧"
	@rm -f $(OBJ)
	@echo "✧ DONE ✧"

fclean: clean
	@echo "✧ REMOVING BINARIES ✧"
	@rm -f $(NAME) $(UNIT)
	@echo "✧ DONE ✧"

re: fclean all

.PHONY:	all	%.o	clean	fclean	re
				src/the_loop_of_shell.c							\