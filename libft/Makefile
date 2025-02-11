# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 18:30:28 by ltheveni          #+#    #+#              #
#    Updated: 2024/12/07 09:42:16 by ltheveni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_isalpha.c\
	   ft_isdigit.c\
	   ft_isalnum.c\
	   ft_isascii.c\
	   ft_isprint.c\
	   ft_strlen.c\
	   ft_memset.c\
	   ft_bzero.c\
	   ft_memcpy.c\
	   ft_memmove.c\
	   ft_strlcpy.c\
	   ft_strlcat.c\
	   ft_toupper.c\
	   ft_tolower.c\
	   ft_strchr.c\
	   ft_strrchr.c\
	   ft_strncmp.c\
	   ft_memchr.c\
	   ft_memcmp.c\
	   ft_strnstr.c\
	   ft_atoi.c\
	   ft_calloc.c\
	   ft_strdup.c\
	   ft_substr.c\
	   ft_strjoin.c\
	   ft_strtrim.c\
	   ft_split.c\
	   ft_itoa.c\
	   ft_strmapi.c\
	   ft_striteri.c\
	   ft_putchar_fd.c\
	   ft_putstr_fd.c\
	   ft_putendl_fd.c\
	   ft_putnbr_fd.c\
	   get_next_line.c
SRCS_BONUS = ft_lstnew_bonus.c\
			 ft_lstadd_front_bonus.c\
			 ft_lstsize_bonus.c\
			 ft_lstlast_bonus.c\
			 ft_lstadd_back_bonus.c\
			 ft_lstdelone_bonus.c\
			 ft_lstclear_bonus.c\
			 ft_lstiter_bonus.c\
			 ft_lstmap_bonus.c
SRCS_PRINTF = ft_printf/ft_printf.c\
			  ft_printf/ft_utils_printf.c
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
OBJS_PRINTF = $(SRCS_PRINTF:.c=.o)
INCLUDE = -I ../includes/

CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIB = ar rc
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@$(LIB) $(NAME) $(OBJS)
	@$(MAKE) printf
	@echo "\nCompiled"

bonus: $(OBJS_BONUS)
	@$(LIB) $(NAME) $(OBJS) $(OBJS_BONUS)
	@$(MAKE) printf
	@echo "\nCompiled"

printf: $(OBJS_PRINTF)
	@$(LIB) $(NAME) $(OBJS_PRINTF)
	@echo "add printf to lib"

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJS_BONUS) $(OBJS_PRINTF)

fclean:
	$(RM) $(NAME) $(OBJS) $(OBJS_BONUS) $(OBJS_PRINTF)

re: fclean all

.PHONY: all bonus clean fclean re
