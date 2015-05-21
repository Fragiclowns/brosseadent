##	The Makefile for the gras-fdisk folder
##
##
##


SRC=	gras-fdisk.c 				\

NAME= 	test

OBJ= 	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			gcc -o $(NAME) $(OBJ)

clean:		
			rm -rf *.o
			rm -rf $(NAME)

