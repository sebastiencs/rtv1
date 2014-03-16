##
## Makefile for rtv in /home/chapui_s/rendu/MUL_2013_rtv1
## 
## Made by chapui_s
## Login   <chapui_s@epitech.eu>
## 
## Started on  Mon Mar 10 00:02:42 2014 chapui_s
## Last update Sun Mar 16 13:24:48 2014 chapui_s
##

SRC	= main.c \
	  my_puts.c \
	  events.c \
	  print_line.c \
	  sphere.c \
	  plan.c \
	  rotate.c \
	  cone.c \
	  cylindre.c \
	  get_cos_a.c \
	  get_color_obj.c \
	  init_obj.c \
	  is_shadow.c \
	  prepare_shadow.c \
	  luminosity.c \
	  shadow.c

NAME	= rtv1

CFLAGS	= -lmlx -lXext -lX11 -I /usr/include/X11 -lm

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
