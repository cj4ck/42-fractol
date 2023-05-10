# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjackows <cjackows@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 11:34:09 by cjackows          #+#    #+#              #
#    Updated: 2022/05/26 11:34:09 by cjackows         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude
NAME = libft.a
AR = ar rcs
SRC = $(shell find src -iname "*.c")
OBJECTS = $(SRC:.c=.o)

PROGRESS_WIDTH = 20
PROGRESS_DONE_CHAR = 🟩
PROGRESS_TODO_CHAR = ⬜️
CURRENT_PROGRESS = 0
TOTAL_PROGRESS = $(words $(OBJECTS))

all: $(NAME)

$(NAME): ascii-art $(OBJECTS)
	@$(AR) $(NAME) $(OBJECTS)
	@echo " ✅"

$(OBJECTS): %.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	$(eval CURRENT_PROGRESS=$(shell echo $$(($(CURRENT_PROGRESS)+1))))
	$(eval PERCENTAGE=$(shell echo $$(($(CURRENT_PROGRESS)*100/$(TOTAL_PROGRESS)))))
	@if [ $(CURRENT_PROGRESS) -eq $(TOTAL_PROGRESS) ]; then \
		printf "\r\033[48;5;40m[COMPILATION]\033[0m \033[38;5;40m$(PERCENTAGE)%% [$$(printf '%*s' $$(($(CURRENT_PROGRESS)*$(PROGRESS_WIDTH)/$(TOTAL_PROGRESS))) | tr ' ' '$(PROGRESS_DONE_CHAR)')$$(printf '%*s' $$(($(PROGRESS_WIDTH)-($(CURRENT_PROGRESS)*$(PROGRESS_WIDTH)/$(TOTAL_PROGRESS)))) | tr ' ' '$(PROGRESS_TODO_CHAR)')] $<\033[0m"; \
	else \
		printf "\r \033[48;5;40m[COMPILATION]\033[0m \033[38;5;51m$(PERCENTAGE)%% [$$(printf '%*s' $$(($(CURRENT_PROGRESS)*$(PROGRESS_WIDTH)/$(TOTAL_PROGRESS))) | tr ' ' '$(PROGRESS_DONE_CHAR)')$$(printf '%*s' $$(($(PROGRESS_WIDTH)-($(CURRENT_PROGRESS)*$(PROGRESS_WIDTH)/$(TOTAL_PROGRESS)))) | tr ' ' '$(PROGRESS_TODO_CHAR)')] $<"; \
	fi
	@sleep 0.01

clean:
	@for obj in $(OBJECTS); do \
		rm -f $$obj; \
		printf "\033[48;5;160m[DELETED]\033[0m \033[38;5;160m$$obj\033[0m\n"; \
	done
	@printf "\033[0m"

fclean: clean
	@rm -f $(NAME);
	@printf "\033[48;5;160m[DELETED]\033[0m \033[38;5;160m$(NAME)\033[0m\n"; \

re: fclean all

ascii-art:
	@clear
	@echo "\033[38;5;231m                 _____ ________           .____    ._____.    _____  __   "
	@echo "\033[38;5;195m                /  |  |\\_____  \\          |    |   |__\\_ |___/ ____\\/  |_ "
	@echo "\033[38;5;159m               /   |  |_/  ____/   ______ |    |   |  || __ \\   __\\\\\   __\\"
	@echo "\033[38;5;123m              /    ^   /       \\  /_____/ |    |___|  || \\_\\ \\  |   |  |  "
	@echo "\033[38;5;87m              \\____   |\\_______ \\         |_______ \\__||___  /__|   |__|  "
	@echo "\033[38;5;51m                   |__|        \\/                 \\/       \\/  "
	@echo

.PHONY: all clean fclean re



 





