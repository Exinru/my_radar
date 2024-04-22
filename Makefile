##
## EPITECH PROJECT, 2023
## EPITECH PROJECT BS MY_LS
## File description:
## makefile of bs_my_ls
##
CC = gcc

LIBRARIES = -lm -lcsfml-system -lcsfml-graphics

SRC =	$(wildcard src/*.c)

OBJ =	$(SRC:.c=.o)

NAME = my_radar

all: $(NAME)

$(NAME):	$(OBJ)
	$(CC) $(SRC) -o $(NAME) $(LIBRARIES)
clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
