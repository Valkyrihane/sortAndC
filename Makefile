# Makefile

CC	=	gcc -std=c11 -O3

CFLAGS	=	-Wall -Wextra
CFLAGS	+=	-Wshadow -Waggregate-return -Wunreachable-code -Winit-self
CPPFLAGS=	-I include/

SRC	=	src/main.c		\
		src/usage.c		\
		src/tab.c		\
		src/sort_and.c		\

SRC 	+=	src/sort/raddix.c	\
		src/sort/bubble.c	\
		src/sort/insertion.c	\
		src/sort/selection.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	sortAndC

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
