/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_loc_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 21:05:47 by fbafica           #+#    #+#             */
/*   Updated: 2021/12/15 00:15:25 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_valid_key(char *key)
{
	if (ft_isalpha(key[0]) || key[0] == '_')
		return (1);
	ft_putendl_fd("invalid character", 2);
	return (0);
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
			if (is_valid_key(key))
			{
				table_insert_pair(g_minishell.loc_var, key, \
				commands[i] + equal_sign + 1);
			}
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
