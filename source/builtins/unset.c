/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 23:57:32 by fbafica           #+#    #+#             */
/*   Updated: 2021/11/13 00:10:00 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	unset_var(char **commands)
{
	int	i;

	i = 1;
	while (commands[i])
	{
		table_delete_pair(g_var_tables.env_var, commands[i]);
		++i;
	}
	return (1);
}
