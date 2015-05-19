##	The Makefile for the gras-common folder
##
##
##


SRC=	common.h	\
		conio.c 	\
		conio.h 	\
		functions.c \
		test.c 		\

NAME= 	test

OBJ= 	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			gcc -o $(NAME) $(OBJ)

clean:		
			rm -rf *.o
			rm -rf $(NAME)

grospd:
			echo "Lucas est un pd, cela est vrai"

