/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:49:38 by fbafica           #+#    #+#             */
/*   Updated: 2021/10/21 23:52:21 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
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

typedef struct s_command
{
	char				*command;
	struct s_command	*next;
}	t_command;

typedef struct s_commands
{
	t_command	*head;
} t_commands;

void				input_handler(char *input);
void				space_handler(char *input);
int					quotes_handler(char *input);
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
char				**split_but_quotes(char *s);
#endif