/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:49:38 by fbafica           #+#    #+#             */
/*   Updated: 2021/11/11 17:05:43 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define IN 0
# define OUT 1
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <readline/readline.h>
# include <readline/history.h>

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

// typedef struct s_command
// {
// 	char				*command;
// 	struct s_command	*next;
// }	t_command;

// typedef struct s_commands
// {
// 	t_command	*head;
// }	t_commands;

typedef struct s_var_tables
{
	t_table	*loc_var;
	t_table	*env_var;
}	t_var_tables;

t_var_tables		g_var_tables;
void				create_var_tables(void);
int					run_shell(void);
void				space_handler(char **input);
int					quotes_check(char *input);
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
char				**get_tokens(char *s);
void				print_tokens(char **tokens);
void				free_tokens(char **tokens);
int					get_tokens_len(char **tokens);
char				**sub_tokens(char **tokens, int start, int end);
int					parser(char **tokens);
int					exec(char **commands);
int					is_builtin(char **commands);
int					find_pipe_operator(char **tokens);
void				save_std_fd(int *std_fd);
void				restore_std_fd(int *std_fd);
void				handle_pipe_fd(int is_pipe);
int					echo(char **commands);
int					cd(char **commands);
char				*get_curr_dir(void);
int					pwd(void);
void				manage_pipe(int is_pipe);
#endif