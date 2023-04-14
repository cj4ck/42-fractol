# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjackows <cjackows@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/14 14:21:45 by cjackows          #+#    #+#              #
#    Updated: 2023/04/14 14:36:51 by cjackows         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = MLX42-TEST
# gcc main.c libmlx42.a -Iinclude -lglfw -L"/Users/cjackows/goinfre/.brew/opt/glfw/lib/"
CC = gcc
# CFLAGS = 
#	-O3 -fsanitize=address -Wall -Wextra -Werror

LIBFT_DIR = ./libft
SRCS_DIR = ./
HDRS_DIR = ./
MLX_DIR = ./

LIBFT = $(LIBFT_DIR)libft.a
MLX = $(MLX_DIR)libmlx.a
SRCS =	$(shell find src/. -iname "*.c")
OBJS = $(SRCS:%.c=%.o)

#compile objs with -I to include directories with header files
HDRS = -I$(HDRS_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

#compile executable with -L/-l to include directories with libraries/libraries
#themselves.
LIBS = libft/libft.a libmlx42.a -Iinclude -lglfw -L"/Users/cjackows/goinfre/.brew/opt/glfw/lib/" -o MLX42-TEST
# -lft -lmlx -lm -framework OpenGL -framework AppKit

#compiles source files without linking. Is used to only update the source files
#neccessary. If you would compile all the .c files everytime one of them
#changes, your Makefile would be slower.

%.o: %.c
	$(CC) $(CFLAGS) $(HDRS) -c $^ -o $@

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(LIBS) $(OBJS) -o $(NAME)
# $(MLX)

$(LIBFT):
	make -C $(LIBFT_DIR)

# $(MLX):
# 	make -C $(MLX_DIR)

Bonus:

#mlx clean removes the mlx archive, not just objects. I changed that.
clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)
#	make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
#	make fclean -C $(MLX_DIR)

re: fclean all

refast:
	rm -f $(OBJS)
	rm -f $(NAME)
	make all

.PHONY: all clean fclean re refast leaks norminette bonus
