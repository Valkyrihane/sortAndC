# Makefile

CC	=	gcc -O3

CFLAGS	=	-W -Wall -Wextra
CPPFLAGS=	-I include/

SRC	=	src/main.c		\
		src/usage.c		\
		src/list.c		\

SRC 	+=	src/sort/raddix.c	\
		src/sort/bubble.c	\
		src/sort/insert.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	linkedSort

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
