/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 21:05:47 by fbafica           #+#    #+#             */
/*   Updated: 2021/12/06 17:33:56 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
