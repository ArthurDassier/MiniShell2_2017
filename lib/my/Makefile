##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## a_makefile_for_the_lib
##

CC=		gcc -g3

OBJ=		$(SRC:.c=.o)

NAME=		libmy.a

CFLAGS	+=	-Wall -Wextra

CPPFLAGS	+=	-I./../include

SRC=		my_printf/cases.c		\
		my_printf/cases2.c		\
		my_printf/cases3.c		\
		my_printf/my_printf.c		\
		convert.c			\
		my_getnbr.c			\
		my_put_nbr_base_long.c		\
		my_put_nbr_base.c		\
		my_put_nbr.c			\
		my_putchar.c			\
		my_puterror.c			\
		my_putstr.c			\
		my_realloc.c			\
		my_revstr.c			\
		my_strcat.c			\
		my_strcpy.c			\
		my_strfind.c			\
		my_strlen.c			\
		my_strncmp.c			\
		my_strncpy.c			\
		my_swap.c			\
		my_str_to_wordtab.c		\


all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		cp $(NAME) ../

.PHONY:		clean

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
