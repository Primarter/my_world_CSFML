##
## EPITECH PROJECT, 2019
## makefile infin_add
## File description:
## compile src, lib, tests, etc
##

SRC	=	src/main.c						\
		src/misc/array_handling.c		\
		src/misc/angle_handling.c		\
		src/misc/destroy.c				\
		src/map/iso_proj.c				\
		src/update/update.c				\
		src/update/table_gestion.c		\
		graphic_lib/framebuffer.c		\
		graphic_lib/manage_keyboard.c	\
		graphic_lib/my_graphic_func.c	\
		graphic_lib/my_draw_func.c		\
		graphic_lib/events.c			\
		graphic_lib/button.c

CFLAGS = -W -Wall -Wextra -lm -lcsfml-graphics -lcsfml-window -Iinclude -g3

LDFLAGS = -L./ -lmy

OBJ	=	$(SRC:.c=.o)

OBJ_TEST	=	$(SRC_TEST:.c=.o)

NAME	=	my_world

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ./lib/my
	gcc $(OBJ) -o $(NAME) $(CFLAGS) $(LDFLAGS)
	find -name "*.o" -type f -delete
clean:
	rm -f $(OBJ)
fclean:	clean
	rm -f $(NAME)
	find -type f -name libmy.a -delete
	find -type f -name *.o -delete
	find -type f -name unit_tests -delete
re:	fclean all