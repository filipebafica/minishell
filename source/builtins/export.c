/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:48:25 by fbafica           #+#    #+#             */
/*   Updated: 2021/11/30 22:50:42 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_env_var(char *var_key, char *var_value)
{
	table_insert_pair(g_minishell.env_var, var_key, var_value);
	if (search_a_key(g_minishell.loc_var, var_key))
		table_delete_pair(g_minishell.loc_var, var_key);
}

int	export_var(char **commands)
{
	int	i;

	i = 0;
	while (commands[i])
	{
		if (i - 2 >= 0 && !ft_strcmp(commands[i], "="))
			handle_env_var(commands[i - 1], commands[i + 1]);
		++i;
	}
	return (1);
}
