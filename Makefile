NAME	= pipex

SRC_FILE 	=	main.c utils1.c utils2.c utils3.c pipex.c here_doc.c

HDR		=	inc/pipex.h

LIB		=	libft/libft.a

SRCS		=	${addprefix src/, ${SRC_FILE}}

CFLAGS		=	-Wall -Wextra -Werror -fsanitize=address -g

# Regular Colors
#Black=\033[0;30m        # Black
#Red=\033[0;31m          # Red
Green=\033[0;32m        # Green
#Yellow=\033[0;33m       # Yellow
#Blue=\033[0;34m         # Blue
#Purple=\033[0;35m       # Purple
Cyan=\033[0;36m         # Cyan
White=\033[0;37m        # White

all: $(NAME)

$(NAME): $(LIB) $(SRC)
	@ cc $(CFLAGS) $(SRCS) $(LIB) -o $(NAME)
	@ echo "${Green}pipex${White}is ready"

$(LIB):
	@ make -C ./libft --no-print-directory --silent
	@ echo "${Green}libft${White}compiled"

clean:
	@ make clean -C ./libft --no-print-directory --silent
	@ /bin/rm -f $(OBJ)
	@ echo "${Cyan}object files${White}deleted"
	
fclean: clean
	@ make fclean -C ./libft --no-print-directory --silent
	@ /bin/rm -f $(NAME)
	@ echo "${Cyan}object and library files${White}deleted"
re: fclean all
.PHONY: all clean fclean re
