##
## Makefile for lol in /home/fossae_t/rendu/CPE_2015_n4s
## 
## Made by Thomas Fossaert
## Login   <fossae_t@epitech.net>
## 
## Started on  Tue Apr 26 10:40:15 2016 Thomas Fossaert
## Last update Thu May 26 15:04:37 2016 Thomas HUGUET
##

SRC=		src/main.c \
		src/error.c \
		src/get_next_line.c \
		src/my_str_to_wordtab.c \
		src/best_driver.c \
		src/fonction.c

OBJ=            $(SRC:.c=.o)

NAME=		ia

all:		$(NAME)


$(NAME):	$(OBJ)
		cc -o $(NAME) $(OBJ) -W -Wall -Werror -Iinc

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
