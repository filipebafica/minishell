/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:18:35 by fbafica           #+#    #+#             */
/*   Updated: 2021/11/12 14:49:08 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_local_var(char *var_name, char *var_value)
{
	table_insert_pair(g_var_tables.env_var, var_name, var_value);
}

static void	handle_env_var(char *command, char *var_name, char *var_value)
{
	if (!ft_strcmp(command, "export"))
		table_insert_pair(g_var_tables.env_var, var_name, \
		var_value);
	else
		table_delete_pair(g_var_tables.env_var, var_name);
}

void	expand_var(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		if (!ft_strcmp(tokens[i], "="))
		{
			if (i - 2 >= 0 && (!ft_strcmp(tokens[i - 2], "export") \
			|| !ft_strcmp(tokens[i - 2], "unset")))
				handle_env_var(tokens[i - 2], tokens[i - 1], tokens[i + 1]);
			else
				handle_local_var(tokens[i - 1], tokens[i + 1]);
		}
		++i;
	}
}

void	started_env_to_var_table(char **started_env)
{
	char	*key;
	char	*value;
	int		i;

	i = 0;
	while (started_env[i])
	{
		key = ft_substr(started_env[i], 0, ft_strchrlen(started_env[i], '='));
		value = ft_strchr(started_env[i], '=') + 1;
		table_insert_pair(g_var_tables.env_var, key, value);
		free(key);
		++i;
	}
}

void	create_var_tables(void)
{
	g_var_tables.loc_var = create_table(100);
	g_var_tables.env_var = create_table(get_tokens_len(__environ) * 3);
}
