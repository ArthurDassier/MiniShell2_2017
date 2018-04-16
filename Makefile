##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## a_makefile_for_projetcs
##

CC	=	gcc -g3

RM	=	rm -rf

CFLAGS	+=	-Wall -Wextra

CFLAGS	+=	-I./include

NAME	=	mysh

SRCS	=	srcs/main.c		\
		srcs/shell.c		\
		srcs/chainlist.c	\
		srcs/simple_com.c	\
		srcs/get_next_line.c	\
		srcs/cd_build.c		\
		srcs/env.c		\
		srcs/err_env.c		\
		srcs/builds.c		\
		srcs/pipe.c		\

OBJS	=	$(SRCS:.c=.o)

LIB =		-L./lib -lmy

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./lib/my
	$(CC) $(OBJS) -o $(NAME) $(LIB)

clean:
	$(RM) $(OBJS)
	make -C ./lib/my clean

fclean: clean
	$(RM) $(NAME)
	$(RM) lib/*.a
	make -C ./lib/my fclean


re: fclean all

.PHONY: all clean fclean re
