# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjackows <cjackows@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 18:32:51 by cjackows          #+#    #+#              #
#    Updated: 2023/05/10 14:07:42 by cjackows         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED			=	\033[38;5;160m
RED_B		=	\033[48;5;160m
DELETED		=	\033[48;5;160m[DELETED]\033[0m
GREEN		=	\033[38;5;40m
GREEN_B		=	\033[48;5;40m
COMPILATION	=	\033[48;5;40m[COMPILATION]\033[0m $(GREEN)
BLUE		=	\033[38;5;123m
BLUE_B		=	\033[48;5;39m
INFO		=	\033[48;5;39m[INFORMATION]\033[0m $(BLUE)
RESET		=	\033[0m
PROGRESS_WIDTH = 20
PROGRESS_DONE_CHAR = 🟩
PROGRESS_TODO_CHAR = ⬜️
CURRENT_PROGRESS = 0
TOTAL_PROGRESS = $(words $(OBJ))

NAME		=	fractol
CC			=	cc
CFLAGS		=	-O3
# -fsanitize=address 
#-Wall -Wextra -Werror
LIBFT		=	./inc/libft/libft.a
LIBFT_DIR	=	./inc/libft/
HDRS_DIR	=	./inc/
SRC_DIR		=	./src
OBJ_DIR		=	./obj

ifeq ($(shell uname), Linux)
	OS			=	Linux

else
	OS				=	Mac
	MLX_DIR 		=	./inc/mlx/mlx_mac
	MLX_LIB			=	$(MLX_DIR)/libmlx.a
	MLX_FLAGS		=	-framework OpenGL -framework AppKit -lz
	DEFINE_FLAGS 	= 	-DKEY_ESC=53 -DKEY_LEFT=123 -DKEY_RIGHT=124 -DKEY_UP=126 -DKEY_DOWN=125\
						-DKEY_W=13 -DKEY_A= -DKEY_S=1 -DKEY_D=2\
						-DKEY_I=34 -DKEY_O=31\
						-DKEY_C=8 -DKEY_Q=12 -DKEY_R=15\
						-DMOUSE_LEFT=1 -DMOUSE_RIGHT=2 -DMOUSE_SCR_UP=5 -DMOUSE_SCR_DOWN=4\
						-DKEY_0=82 -DKEY_1=18 -DKEY_2=19 -DKEY_3=20 -DKEY_4=21 -DKEY_5=22 -DKEY_6=23\
						-DKEY_7=24 -DKEY_8=25 -DKEY_9=26 -DKEY_H=4 -DKEY_J=38 -DKEY_K=40 -DKEY_L=37
endif

SRC			=	$(wildcard $(SRC_DIR)/*.c)
HDRS 		=	-I$(LIBFT_DIR)/inc -I$(MLX_DIR) -I$(HDRS_DIR)
LIBS		=	-L$(LIBFT_DIR) -L$(MLX_DIR) $(MLX_FLAGS)
OBJ			=	$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

all: $(NAME)

$(NAME): mlx libft ascii-art $(OBJ)
	@echo
	@echo "$(COMPILATION)$(NAME) compilation with $(OS)-flags.$(RESET)"
	@$(CC) $(CFLAGS) $(LIBS) $(OBJ) -o $(NAME) $(LIBFT) $(MLX_LIB)
	@echo "$(INFO)$@ executable has been created$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) $(DEFINE_FLAGS) $(HDRS) -c $^ -o $@
	$(eval CURRENT_PROGRESS=$(shell echo $$(($(CURRENT_PROGRESS)+1))))
	$(eval PERCENTAGE=$(shell echo $$(($(CURRENT_PROGRESS)*100/$(TOTAL_PROGRESS)))))
	@if [ $(CURRENT_PROGRESS) -eq $(TOTAL_PROGRESS) ]; then \
		printf "\r$(GREEN_B)[COMPILATION]$(RESET) \033[38;5;40m$(PERCENTAGE)%% [$$(printf '%*s' $$(($(CURRENT_PROGRESS)*$(PROGRESS_WIDTH)/$(TOTAL_PROGRESS))) | tr ' ' '$(PROGRESS_DONE_CHAR)')$$(printf '%*s' $$(($(PROGRESS_WIDTH)-($(CURRENT_PROGRESS)*$(PROGRESS_WIDTH)/$(TOTAL_PROGRESS)))) | tr ' ' '$(PROGRESS_TODO_CHAR)')] $<\033[0m ✅                   "; \
	else \
		printf "\r$(GREEN_B)[COMPILATION]$(RESET) \033[38;5;51m$(PERCENTAGE)%% [$$(printf '%*s' $$(($(CURRENT_PROGRESS)*$(PROGRESS_WIDTH)/$(TOTAL_PROGRESS))) | tr ' ' '$(PROGRESS_DONE_CHAR)')$$(printf '%*s' $$(($(PROGRESS_WIDTH)-($(CURRENT_PROGRESS)*$(PROGRESS_WIDTH)/$(TOTAL_PROGRESS)))) | tr ' ' '$(PROGRESS_TODO_CHAR)')] $<"; \
	fi
	@sleep 0.01


libft:
	@make  -C  $(LIBFT_DIR)
	@clear

mlx:
	@make  -C  $(MLX_DIR)
	@clear

clean:
#	@make clean -C $(LIBFT_DIR)
	@printf "$(RED_B)[DELETED]$(RESET) $(RED)$(MLX_DIR)\n"
	@for obj in $(OBJ); do \
		rm -f $$obj; \
		printf "$(RED_B)[DELETED]$(RESET) $(RED)$$obj$(RESET)\n"; \
	done

fclean: clean
	@make clean --quiet -C $(MLX_DIR)
	@make fclean --quiet -C $(LIBFT_DIR)
	@rm -f $(NAME);
	@printf "$(RED_B)[DELETED]$(RESET) $(RED)$(NAME)$(RESET)\n"; \

re: fclean all

sre: clean all

git:
	@echo "$(BLUE)"
	git add *
	@read -p "Commit msg:" msg;\
	git commit -m "$$msg"
	git push
	@echo "$(INFO)$(GREEN)Git add, commit, push performed ✅$(RESET)"

ascii-art:
	@echo "\033[38;5;51m                                      \`\\/,"
	@echo "\033[38;5;51m                                     .- '--."
	@echo "\033[38;5;51m                                    '       \`"
	@echo "\033[38;5;51m                                    \`.      .'        _."
	@echo "\033[38;5;51m                            \`._  .-~'       \`~-.   _,'"
	@echo "\033[38;5;87m                             ( )'              '.( )"
	@echo "\033[38;5;87m               \`._    _       /                  .'       ."
	@echo "\033[38;5;87m                ( )--' \`-.  .'                     ;   _\`"
	@echo "\033[38;5;87m          .    .'        '.;                         ()' "
	@echo "\033[38;5;87m           \`.-.\`           '                        :"
	@echo "\033[38;5;231m        .  .    _____ ________          ___________\`                    __  /\      .__   \033[0m"
	@echo "\033[38;5;195m          ,    /  |  |\_____  \         \_   _____/___________    ____ /  |_)/ ____ |  |  \033[0m"
	@echo "\033[38;5;159m   ---*=::    /   |  |_/  ____/   ______ |    __) \_  __ \__  \  / ___\\\\\   __\/  _ \|  |  \033[0m"
	@echo "\033[38;5;123m        \`:   /    ^   /       \  /_____/ |     \   |  | \// __ \/  \___ |  | (  <_> )  |__\033[0m"
	@echo "\033[38;5;123m         .,  \____   |\_______ \         \___  /   |__|  (____  /\___  >|__|  \____/|____/\033[0m"
	@echo "\033[38;5;123m        .  .      |__|        \/             \/    by cj4ck   \/     \/                  \033[0m"
	@echo "\033[38;5;123m            .\`-'.           ,                     \`."
	@echo "\033[38;5;123m           '    '.        .';                       () "
	@echo "\033[38;5;159m                (_)-   .-'  \`.                      ;\`.         "
	@echo "\033[38;5;159m               ,'   \`-'       \\                        '"
	@echo "\033[38;5;159m                            (_).                   _'     '"
	@echo "\033[38;5;159m                            .'   '-._         .-.'(_)      "
	@echo "\033[38;5;195m                                    .'       \`.     \`.     "
	@echo "\033[38;5;231m                                    '         ;       '    "
	@echo "\033[38;5;195m                                     \`-.,. -'              "
	@echo "\033[38;5;231m                                        /\\\               "
	@echo

.PHONY: all clean fclean re sre git mlx libft