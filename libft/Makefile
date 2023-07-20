NAME = libft.a

SRC_LIB =	libft/ft_isalpha.c libft/ft_isdigit.c libft/ft_isalnum.c libft/ft_isascii.c\
			libft/ft_isprint.c libft/ft_strlen.c libft/ft_memset.c libft/ft_bzero.c\
			libft/ft_memcpy.c libft/ft_memmove.c libft/ft_strlcpy.c libft/ft_strlcat.c\
			libft/ft_toupper.c libft/ft_tolower.c libft/ft_strchr.c libft/ft_strrchr.c\
			libft/ft_strncmp.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_strnstr.c\
			libft/ft_atoi.c libft/ft_calloc.c libft/ft_strdup.c libft/ft_substr.c\
			libft/ft_strjoin.c libft/ft_strtrim.c libft/ft_split.c libft/ft_itoa.c\
			libft/ft_strmapi.c libft/ft_striteri.c libft/ft_putchar_fd.c\
			libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c\
			libft/ft_lstnew.c libft/ft_lstadd_front.c libft/ft_lstsize.c\
			libft/ft_lstlast.c libft/ft_lstadd_back.c libft/ft_lstdelone.c\
			libft/ft_lstclear.c libft/ft_lstiter.c libft/ft_lstmap.c\
			get_next_line/get_next_line.c get_next_line/get_next_line_utils.c\
			ft_printf/ft_printf.c ft_printf/ft_printf_utils1.c \
			ft_printf/ft_printf_utils2.c ft_printf/ft_printf_utils3.c \
#SRC_GNL =	get_next_line/get_next_line.c\
#SRC_FTP =	ft_printf/ft_printf.c ft_printf/ft_printf_utils1.c \
#			ft_printf/ft_printf_utils2.c ft_printf/ft_printf_utils3.c \

CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC_LIB:.c=.o)
#OBJ_GNL = $(SRC_GNL:.c=.o)
#OBJ_FTP = $(SRC_FTP:.c=.o)

.c.o:
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)
#	cp $(OBJ_GNL) $(NAME)
#	cp $(OBJ_FTP) $(NAME)

all: $(NAME)

clean:
	/bin/rm -f $(OBJ) 
#	/bin/rm -f $(OBJ_GNL)
#	/bin/rm -f $(OBJ_FTP)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
