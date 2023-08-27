#Variables
NAME = libft.a
CC = CC
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

#PATHS
VPATH	=	src:src/conversion:src/list:src/memory:src/output:src/string
SRCS	=	ft_isalpha.c ft_isdigit.c
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
