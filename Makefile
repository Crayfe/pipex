# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cayuso-f <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 16:58:10 by cayuso-f          #+#    #+#              #
#    Updated: 2025/01/28 16:57:50 by cayuso-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
SRC_DIR = src
OBJ_DIR = obj
BONUS_SRC_DIR = src_bonus
BONUS_OBJ_DIR = obj_bonus

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

BONUS_SRCS = $(wildcard $(BONUS_SRC_DIR)/*.c)
BONUS_OBJS = $(patsubst $(BONUS_SRC_DIR)/%.c,$(BONUS_OBJ_DIR)/%.o,$(BONUS_SRCS))

NAME = pipex
BONUS_NAME = pipex_bonus

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_DIR)/libft.a
	$(CC) $(CFLAGS) -o $@ $^ -L $(LIBFT_DIR) -lft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(LIBFT_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT_DIR)/libft.a:
	@echo "Compilando libft..."
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR) $(BONUS_OBJ_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT_DIR)/libft.a
	$(CC) $(CFLAGS) -o $@ $^ -L $(LIBFT_DIR) -lft

$(BONUS_OBJ_DIR)/%.o: $(BONUS_SRC_DIR)/%.c | $(BONUS_OBJ_DIR)
	$(CC) $(CFLAGS) -I $(LIBFT_DIR) -c $< -o $@

$(BONUS_OBJ_DIR):
	mkdir -p $(BONUS_OBJ_DIR)

.PHONY: all clean fclean re bonus