#Variables
NAME = libft.a
CC = CC
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

#PATHS
#VPATH	=	src:src/conversion:src/list:src/memory:src/output:src/string
SRCS	=	ft_isdigit.c ft_strlen.c ft_bzero.c ft_isascii.c ft_memcpy.c \
			ft_isprint.c ft_isalpha.c ft_memset.c ft_isalnum.c ft_memmove.c \
			ft_strlcpy.c ft_strlcat.c
MY_OBJECTS = $(SRCS:.c=.o)

#Rules
all: $(NAME)

$(NAME): $(MY_OBJECTS)
	ar rcs $(NAME) $(MY_OBJECTS)

clean:
	rm -f $(MY_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
