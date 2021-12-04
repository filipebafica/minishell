/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:52:38 by fbafica           #+#    #+#             */
/*   Updated: 2021/12/03 19:16:55 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exit_shell(char **commands)
{
	if (get_tokens_len(commands) > 1)
	{
		ft_putendl_fd("exit: too many arguments", STDERR_FILENO);
		table_insert_pair(g_minishell.error_status, "?", "1");
		return (1);
	}
	table_insert_pair(g_minishell.error_status, "?", "0");
	return (0);
}
