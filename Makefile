NAME	= cub3D

CFLAGS	= -Wall -Wextra -Werror

CC		= gcc

HEADER		= cub3d.h

SRCS	= ./parser/check_type.c \
         ./parser/color.c \
          ./utils/draw_map.c \
          ./get_next_line/get_next_line.c \
          ./get_next_line/get_next_line_utils.c \
          ./utils/init_all.c \
          ./parser/list_to_map.c \
          main.c \
          ./parser/map_func.c \
          ./raycasting/moves.c \
          ./parser/parser.c \
          ./parser/parsing_gnl.c \
          ./utils/utils.c \
          ./raycasting/raycasting_colors.c \
          ./utils/free_and_close.c \
          ./raycasting/draw_game.c \
          ./raycasting/raycasting.c

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
