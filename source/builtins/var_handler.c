/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 21:05:47 by fbafica           #+#    #+#             */
/*   Updated: 2021/11/30 22:51:14 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	expand_var(char *commands)
{
	char	**new_command;
	char	*var_value;

	var_value = search_a_key(g_minishell.env_var, ++commands);
	if (!var_value)
		var_value = search_a_key(g_minishell.loc_var, commands);
	if (var_value)
	{
		new_command = malloc(sizeof(char *) * 2);
		new_command[0] = ft_strdup(var_value);
		new_command[1] = (char *) '\0';
		select_exec_type(new_command, 0);
		free_tokens(new_command);
	}
	return (1);
}

int	create_local_vars(char **commands)
{
	char	*key;
	int		equal_sign;
	int		i;

	i = 0;
	while (commands[i])
	{
		equal_sign = ft_strchrlen(commands[i], '=');
		if (equal_sign)
		{
			key = ft_substr(commands[i], 0, equal_sign);
			table_insert_pair(g_minishell.loc_var, key, \
			commands[i] + equal_sign + 1);
			free(key);
		}
		++i;
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
