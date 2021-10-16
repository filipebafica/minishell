/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:49:38 by fbafica           #+#    #+#             */
/*   Updated: 2021/10/15 21:48:42 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_node
{
	char	*key;
	char	*value;
}	t_node;

typedef struct s_table
{
	t_node	**data;
	int		count;
	int		size;
}	t_table;

void				input_handler(char **input);
void				space_handler(char **input);
int					quotes_handler(char **input);
unsigned long int	hash_a_key(char *key, unsigned int table_size);
t_table				*create_table(int size);

#endif