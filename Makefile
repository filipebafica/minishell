# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/08 14:36:44 by fbafica           #+#    #+#              #
#    Updated: 2021/12/15 00:12:10 by fbafica          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

LIBFT_INCLUDE = ./libft/includes/
LIBFT = ./libft/libft.a

FT_PRINTF_INCLUDE = ./ft_printf/includes/
FT_PRINTF = ./ft_printf/ft_printf.a

INCLUDE_PATH = ./includes/
FLAGS = -g -Wall -Wextra -Werror -lreadline
SOURCE_CODE = ./source/main.c \
./source/shell/run_shell.c \
./source/signals/signals.c ./source/signals/here_doc_signals.c \
./source/vars/vars_tab_utils1.c \
./source/parser/parser.c  ./source/parser/fd_handler.c ./source/parser/pipe_parser.c ./source/parser/redirect_parser.c \
./source/parser/here_doc.c \
./source/exec/exec.c ./source/exec/exec_builtin.c ./source/exec/exec_non_builtin.c ./source/exec/path_handler.c \
./source/builtins/echo.c ./source/builtins/cd.c ./source/builtins/pwd.c ./source/builtins/exit.c \
./source/builtins/env.c ./source/builtins/export.c ./source/builtins/unset.c ./source/builtins/create_loc_var.c \
./source/builtins/export_sorted.c ./source/builtins/export_vars.c \
./source/input_handler/space_handler.c ./source/input_handler/quotes_check.c ./source/input_handler/get_tokens.c \
./source/input_handler/expand_var_1.c ./source/input_handler/expand_var_2.c ./source/input_handler/remove_double_quotes.c \
./source/input_handler/tokens_utils1.c ./source/input_handler/tokens_utils2.c ./source/input_handler/init_end_check.c  \
./source/input_handler/no_input_check.c ./source/input_handler/bad_redirect_check.c ./source/input_handler/bad_equal_check.c \
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

install:
	sudo apt-get install libreadline7
	sudo apt-get install libreadline-dev

