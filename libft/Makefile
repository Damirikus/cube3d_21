SRC_NAME =	 ft_atoi.c ft_strlen.c ft_strlcpy.c ft_strlcat.c  ft_itoa.c 
			
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(SRC_NAME)
OBJ = $(addprefix ,$(OBJ_NAME))
CC = gcc
CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = -I.
NAME = libft.a

all : $(NAME)

$(NAME) : $(OBJ) libft.h
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$%.o: $(SRC_PATH)%.c 
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: clean fclean all re	