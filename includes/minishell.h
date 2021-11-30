/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:49:38 by fbafica           #+#    #+#             */
/*   Updated: 2021/11/30 13:12:33 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define IN 0
# define OUT 1
# define TMP_FILE "/tmp/tmp_heredoc_minishell"
# define COLOR_RED "\x1b[1;31m"
# define COLOR_RESET "\x1b[0m"
# include "libft.h"
# include "ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>

typedef struct s_pair
{
	char			*key;
	char			*value;
	struct s_pair	*next;
}	t_pair;

typedef struct s_table
{
	t_pair	**pairs;
	int		count;
	int		size;
}	t_table;

typedef struct s_var_tables
{
	t_table	*loc_var;
	t_table	*env_var;
}	t_var_tables;

				/*
				* INIT SHELL 
				*/
t_var_tables		g_var_tables;
int					run_shell(void);
				/*
				* VARS 
				*/
void				create_var_tables(void);
void				env_var_arr_to_env_var_table(char **env_var);
char				**env_var_arr_table_to_env_var(void);
				/*
				* INPUT HANDLER 
				*/
int					no_input_check(char *input);
int					init_end_check(char *input);
int					bad_redirect_check(char *input);
int					bad_equal_check(char *input);
void				space_handler(char **input);
int					quotes_check(char *input);
char				**get_tokens(char *s);
void				print_tokens(char **tokens);
void				free_tokens(char **tokens);
int					get_tokens_len(char **tokens);
char				**sub_tokens(char **tokens, int start, int end);
char				**join_tokens(char **tokens1, char **tokens2);
void				delete_a_token(char ***tokens, int index);
int					check_a_token(char **tokens, char *token_to_check);
				/*
				* HASH TABLE 
				*/
unsigned long int	hash_a_key(char *key, unsigned int table_size);
t_table				*create_table(int size);
t_pair				*create_pair(char *key, char *value);
void				free_pair(t_pair *pair);
void				free_table(t_table *table);
void				free_linked_pair(t_pair *pair);
void				table_insert_pair(t_table *table, char *key, char *value);
void				table_delete_pair(t_table *table, char *key);
char				*search_a_key(t_table *table, char *key);
void				print_search(t_table *table, char *key);
void				print_table(t_table *table);
				/*
				* PARSER 
				*/
int					parser(char **tokens, int tokens_len);
void				replace_std_fd(int *new_fd);
void				save_std_fd(int *fd_holder);
int					find_pipe_operator(char **tokens, int tokens_len);
int					find_redirect_operator(char **tokens, int tokens_len);
int					handle_redirect_files(char **tokens, int tokens_len);
int					here_doc(char *eof_token);
void				create_pipe(int is_pipe);
				/*
				* EXEC 
				*/
int					exec(char **tokens, int tokens_len, int *saved_fd);
int					select_exec_type(char **commands, int pipe_flag);
char				*get_command_and_path(char *command);
int					exec_non_builtin(char **commands);
int					is_builtin(char **commands, int pipe_flag);
int					exec_builtin(char **commands);
				/*
				* BUILTINS 
				*/
int					check_create_local_var(char **commands);
int					create_local_vars(char **commands);
int					expand_var(char *commands);
int					echo(char **commands);
int					cd(char **commands);
char				*get_curr_dir(void);
int					pwd(void);
int					exit_shell(void);
int					env(void);
int					export_var(char **commands);
int					unset_var(char **commands);
#endif