NAME	= cub3D

CFLAGS	= -Wall -Wextra -Werror

CC		= gcc

HEADER		= cub3d.h

SRCS	= check_type.c \
          color.c \
          draw_map.c \
          get_next_line.c \
          get_next_line_utils.c \
          init_all.c \
          list_to_map.c \
          main.c \
          map_func.c \
          moves.c \
          parser.c \
          parsing_gnl.c \
          utils.c

%.o: 	%.c $(HEADER)
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(SRCS) $(HEADER)
			$(MAKE) all -C ./libft
			$(MAKE) all -C ./minilibx
			cp libft/libft.a ./$(NAME)
			cp minilibx/libmlx.a ./$(NAME)
			$(CC) $(SRCS)  -framework OpenGL -framework AppKit ./minilibx/libmlx.a ./libft/libft.a -o $(NAME)

all: $(NAME)

clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./minilibx
	-rm -rf $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	-rm -rf $(NAME)

re:		fclean all

.PHONY: all clean fclean re
