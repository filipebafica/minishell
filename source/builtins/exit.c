/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:52:38 by fbafica           #+#    #+#             */
/*   Updated: 2021/12/11 12:52:17 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_exit_status(char *exit_status)
{
	while (*exit_status)
	{
		if (!ft_isdigit(*exit_status))
			return (0);
		++exit_status;
	}
	return (1);
}

int	exit_shell(char **commands)
{
	if (get_tokens_len(commands) > 2)
	{
		ft_putendl_fd("exit: too many arguments", STDERR_FILENO);
		table_insert_pair(g_minishell.error_status, "?", "1");
		return (1);
	}
	if (get_tokens_len(commands) == 2)
	{
		if (check_exit_status(commands[1]))
			exit(ft_atoi(commands[1]));
		exit(2);
	}
	exit(0);
	return (0);
}
