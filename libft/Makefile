# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cayuso-f <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 16:58:10 by cayuso-f          #+#    #+#              #
#    Updated: 2024/10/02 15:56:17 by cayuso-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# Variables
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRC_DIR = src
OBJ_DIR = obj

# We load all *.c files from SRC directori
SRCS = $(wildcard $(SRC_DIR)/*.c)

# We store all *.o files generated into OBJ directory
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

# Rule to complile static library
$(NAME): $(OBJS)
	@ar rcs $@ $^
	@echo "The library $(NAME) has been created correctly."

# Rule to compile files .c to .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clear the *.o created 
clean:
	@rm -rf $(OBJ_DIR)
	@echo "Object files deleted"

# Clear all, *.o and libft.a
fclean: clean
	@rm -f $(NAME)
	@echo "Library $(NAME) deleted."

# Rule to clear all and remake the project
re: fclean all