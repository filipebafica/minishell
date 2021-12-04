/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 23:57:32 by fbafica           #+#    #+#             */
/*   Updated: 2021/12/03 19:17:50 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	unset_var(char **commands)
{
	int	i;

	i = 1;
	while (commands[i])
	{
		table_delete_pair(g_minishell.env_var, commands[i]);
		++i;
	}
	table_insert_pair(g_minishell.error_status, "?", "0");
	return (1);
}
