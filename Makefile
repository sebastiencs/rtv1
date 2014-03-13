##
## Makefile for rtv in /home/chapui_s/rendu/MUL_2013_rtv1
## 
## Made by chapui_s
## Login   <chapui_s@epitech.eu>
## 
## Started on  Mon Mar 10 00:02:42 2014 chapui_s
## Last update Wed Mar 12 20:00:25 2014 chapui_s
##

SRC	= main.c \
	  my_puts.c \
	  events.c \
	  print_line.c \
	  utils.c \
	  sphere.c \
	  plan.c \
	  rotate.c

NAME	= rtv1

CFLAGS	= -lmlx -lXext -lX11 -I /usr/include/X11 -lm -Wall -Wextra -g

OBJ	= $(SRC:.c=.o)

CC	= gcc

RM	= rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
