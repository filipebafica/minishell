# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/08 14:36:44 by fbafica           #+#    #+#              #
#    Updated: 2021/10/18 22:10:19 by fbafica          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

LIBFT_INCLUDE = ./libft/includes/
LIBFT = ./libft/libft.a

INCLUDE_PATH = ./includes/
FLAGS = -g -fsanitize=address -Wall -Wextra -Werror -lreadline
SOURCE_CODE = ./source/main.c ./source/parser/input_handler.c ./source/parser/space_handler.c \
./source/parser/quotes_handler.c ./source/hashtable/hash_function.c ./source/hashtable/ht_create.c \
./source/hashtable/ht_insert.c ./source/hashtable/ht_delete.c ./source/hashtable/ht_search.c \
./source/hashtable/ht_free.c ./source/hashtable/ht_print.c

CC = gcc

all: $(NAME)

$(NAME): $(SOURCE_CODE) $(LIBFT)
	@$(CC) $^ $(FLAGS) -I$(INCLUDE_PATH) -I$(LIBFT_INCLUDE) -o $@

$(LIBFT):
	@make -C libft

clean:
	@make clean -C libft

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all
