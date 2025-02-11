# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/18 14:00:10 by ltheveni          #+#    #+#              #
#    Updated: 2025/02/11 12:02:50 by ltheveni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
_GREY	= \033[30m
_RED	= \033[31m
_GREEN	= \033[32m
_YELLOW	= \033[33m
_BLUE	= \033[34m
_PURPLE	= \033[35m
_CYAN	= \033[36m
_WHITE	= \033[37m
_END	= \033[0m

NAME = cub3D
LIBFT = libft
SRC_DIR = srcs/
OBJ_DIR = objs/
LIB_DIR = libft/

# Config
SHELL = /bin/bash
CC = gcc

INCLUDE = -I includes
CFLAGS = -Wall -Werror -Wextra
LIBFLAGS = -L $(LIB_DIR) -lft
RM = rm -rf
DEBUG_FLAGS = -g3

# C program
SRCS = $(shell find $(SRC_DIR) -name '*.c')
OBJS = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

# OS ?
UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
	MLX_DIR = minilibx
	MLX_FLAGS = -L $(MLX_DIR) -lmlx -framework OpenGL -framework Appkit
else
	MLX_DIR = minilibx-linux
	MLX_FLAGS = -L $(MLX_DIR) -lmlx -lXext -lX11 -lm
endif

# Recipe
all: $(LIBFT) $(MLX_DIR)/libmlx.a $(NAME)

$(NAME): $(LIB_DIR)$(LIBFT).a $(OBJS) $(MLX_DIR)/libmlx.a
	@printf "$(_END)\nCompiled source files\n"
	@$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LIBFLAGS) $(MLX_FLAGS) -o $@
	@printf "$(_GREEN)Finish compiling $(NAME)!\n"
	@printf "Try \"./$(NAME)\" to use$(_END)\n"

$(LIBFT):
	@make -C $(LIB_DIR)

$(MLX_DIR)/libmlx.a:
	@make -C $(MLX_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@printf "$(_GREEN)█$(_END)"

clean:
	@printf "$(_YELLOW)Removing object files ...$(_END)\n"
	@make clean -C $(LIB_DIR)
	@make clean -C $(MLX_DIR)
	@$(RM) $(OBJ_DIR)

fclean:
	@printf "$(_RED)Removing object files and program ...$(_END)\n"
	@make fclean -C $(LIB_DIR)
	@make clean -C $(MLX_DIR)
	@$(RM) $(NAME) $(OBJ_DIR)

re: fclean all

debug: CFLAGS += -fsanitize=address $(DEBUG_FLAGS)
debug: re
	@printf "$(_BLUE)Debug build done$(_END)\n"

leak: CFLAGS += $(DEBUG_FLAGS)
leak: re
	@printf "$(_BLUE)Leak check build done$(_END)\n"

.PHONY: all clean fclean re libft debug leak
