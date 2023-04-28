# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjackows <cjackows@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/11 13:04:04 by cjackows          #+#    #+#              #
#    Updated: 2023/04/28 14:57:43 by cjackows         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc
CFLAGS = -O3
#-fsanitize=address
#-Wall -Wextra -Werror

LIBFT_DIR = ./inc/libft/
SRCS_DIR = ./
HDRS_DIR = ./inc/
MLX_DIR = ./inc/minilibx_mms_20191025_beta/

LIBFT = $(LIBFT_DIR)libft.a
MLX = $(MLX_DIR)libmlx.dylib
OBJS = $(SRCS:%.c=%.o)

SRCS =	main.c hooks.c color.c mandelbrot.c image_processing.c parsing.c

#compile objs with -I to include directories with header files
HDRS = -I$(HDRS_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

#compile executable with -L/-l to include directories with libraries/libraries
#themselves.
LIBS = -L$(LIBFT_DIR) -L$(MLX_DIR) -lft -lmlx -lm -framework OpenGL \
-framework AppKit

#compiles source files without linking. Is used to only update the source files
#neccessary. If you would compile all the .c files everytime one of them
#changes, your Makefile would be slower.

%.o: %.c
	$(CC) $(CFLAGS) $(HDRS) -c $^ -o $@

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(LIBS) $(OBJS) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

Bonus:

#mlx clean removes the mlx archive, not just objects. I changed that.
clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(MLX_DIR)

leaks:
	leaks --atExit -- ./$(NAME) 1200 Mandelbrot

norminette:
	@norminette $(SRCS)
	@make norminette -C $(LIBFT_DIR) 

re: fclean all

refast:
	rm -f $(OBJS)
	rm -f $(NAME)
	make all

.PHONY: all clean fclean re refast leaks norminette bonus
