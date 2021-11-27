/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 21:05:47 by fbafica           #+#    #+#             */
/*   Updated: 2021/11/27 14:39:39 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	expand_var(char *commands)
{
	char	**new_command;
	char	*var_value;

	var_value = search_a_key(g_var_tables.env_var, ++commands);
	if (!var_value)
		var_value = search_a_key(g_var_tables.loc_var, commands);
	new_command = malloc(sizeof(char *) * 2);
	new_command[0] = ft_strdup(var_value);
	new_command[1] = (char *) '\0';
	select_exec_type(new_command);
	free_tokens(new_command);
	return (1);
}

int	create_local_vars(char **commands)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (commands[i])
	{
		if (ft_strcmp(commands[i], "=") && commands[i + 1] \
		&& !ft_strcmp(commands[i + 1], "="))
			j = i;
		++i;
		while (commands[i] && !ft_strcmp(commands[i], "="))
			++i;
		if (commands[i] && commands[j])
		{
			table_insert_pair(g_var_tables.loc_var, commands[j], commands[i]);
			++i;
		}
	}
	return (1);
}

int	check_create_local_var(char **commands)
{
	int	i;

	i = 0;
	while (commands[i])
	{
		if (ft_strchr(commands[i], '='))
			return (1);
		++i;
	}
	return (0);
}
