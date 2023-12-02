##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## a makefile for Jam Game
##

SRCS =	$(wildcard *.c)

OBJS = $(SRCS:.c=.o)

NAME = jamgame

CC =	gcc

all: $(NAME)

$(NAME):$(OBJS)
	$(CC) -o $(NAME) $(OBJS) -lcsfml-graphics -lcsfml-audio -lcsfml-system

clean:
	rm -rf *.o

fclean: clean
	rm -rf *.a

re: fclean all
