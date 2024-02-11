##
## EPITECH PROJECT, 2023
## makefile
## File description:
## my own makefile
##
CC = gcc
NAME = my_navy
SRCS =	$(wildcard *.c)

OBJS = $(SRCS:.c=.o)
all:$(NAME)

$(NAME) : $(OBJS)
	$(CC) $(SRCS) -o $(NAME)
clean :
	rm -rf *.o
fclean: clean
	rm -rf *~ *# $(NAME)
re: fclean all
