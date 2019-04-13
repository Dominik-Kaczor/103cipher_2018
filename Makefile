##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## 103cipher.c
##

SRC	=	src/encrypted.c	\
		src/main.c	\
		src/decrypted.c	\
		src/tools_decrypted.c	\
		src/tools.c	\

NAME	=	103cipher

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) -lm

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re:	fclean all
