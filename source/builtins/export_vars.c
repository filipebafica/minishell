/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_vars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 23:53:42 by fbafica           #+#    #+#             */
/*   Updated: 2021/12/15 00:15:43 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	insert_env_var(char *var_key, char *var_value)
{
	table_insert_pair(g_minishell.env_var, var_key, var_value);
	if (search_a_key(g_minishell.loc_var, var_key))
		table_delete_pair(g_minishell.loc_var, var_key);
}

static int	is_valid_key(char *key)
{
	if (ft_isalpha(key[0]) || key[0] == '_')
		return (1);
	ft_putendl_fd("invalid character", 2);
	return (0);
}

int	export_var(char **commands)
{
	char	*key;
	char	*value;
	int		equal_sign;
	int		i;

	i = 0;
	while (commands[i])
	{
		equal_sign = ft_strchrlen(commands[i], '=');
		if (equal_sign)
		{
			key = ft_substr(commands[i], 0, equal_sign);
			value = ft_strdup(commands[i] + equal_sign + 1);
			if (is_valid_key(key))
				insert_env_var(key, value);
			free(key);
			free(value);
		}
		++i;
	}
	return (1);
}
