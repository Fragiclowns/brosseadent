##	The Makefile for the gras-fdisk folder
##
##
##


SRC=	../gras-common/common.h		\
		../gras-common/conio.c 		\
		../gras-common/conio.h 		\
		../gras-common/functions.c 	\
		../gras-common/test.c 		\
		gras-fdisk.c 				\

NAME= 	test

OBJ= 	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			gcc -o $(NAME) $(OBJ)

clean:		
			rm -rf *.o
			rm -rf $(NAME)

