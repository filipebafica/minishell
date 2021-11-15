# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/08 14:36:44 by fbafica           #+#    #+#              #
#    Updated: 2021/11/15 18:17:35 by fbafica          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

LIBFT_INCLUDE = ./libft/includes/
LIBFT = ./libft/libft.a

FT_PRINTF_INCLUDE = ./ft_printf/includes/
FT_PRINTF = ./ft_printf/ft_printf.a

INCLUDE_PATH = ./includes/
FLAGS = -g -fsanitize=address -Wall -Wextra -Werror -lreadline
SOURCE_CODE = ./source/main.c \
./source/shell/run_shell.c ./source/shell/vars_utils1.c ./source/shell/vars_utils2.c \
./source/parser/parser.c ./source/parser/find_operator.c ./source/parser/handle_fd.c \
./source/exec/exec.c \
./source/builtins/echo.c ./source/builtins/cd.c ./source/builtins/pwd.c ./source/builtins/exit.c \
./source/builtins/env.c ./source/builtins/export.c ./source/builtins/unset.c \
./source/input_handler/space_handler.c ./source/input_handler/quotes_check.c ./source/input_handler/get_tokens.c \
./source/input_handler/tokens_utils.c ./source/input_handler/init_end_check.c ./source/input_handler/no_input_check.c \
./source/hashtable/hash_function.c ./source/hashtable/ht_create.c ./source/hashtable/ht_insert.c ./source/hashtable/ht_delete.c \
./source/hashtable/ht_search.c ./source/hashtable/ht_free.c ./source/hashtable/ht_print.c \

CC = gcc

all: $(NAME)

$(NAME): $(SOURCE_CODE) $(LIBFT) $(FT_PRINTF)
	@$(CC) $^ $(FLAGS) -I$(INCLUDE_PATH) -I$(LIBFT_INCLUDE) -I$(FT_PRINTF_INCLUDE) -o $@

$(LIBFT):
	@make -C libft

$(FT_PRINTF):
	@make -C ft_printf

clean:
	@make clean -C libft
	@make clean -C ft_printf

fclean: clean
	@make fclean -C libft
	@make fclean -C ft_printf
	@rm -f $(NAME)

re: fclean all
