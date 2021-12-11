/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:27:50 by fbafica           #+#    #+#             */
/*   Updated: 2021/12/11 15:31:05 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handler_exec(int signum)
{
	if (signum == SIGINT)
	{
		table_insert_pair(g_minishell.error_status, "?", "130");
		write(1, "\n", 1);
	}
	if (signum == SIGQUIT)
	{
		table_insert_pair(g_minishell.error_status, "?", "131");
		ft_putendl_fd("Quit", 2);
	}
}

static void	handler_non_exec(int signum)
{
	if (isatty(STDIN_FILENO) && signum == SIGINT)
	{
		ft_printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		table_insert_pair(g_minishell.error_status, "?", "130");
	}
	else
		return ;
}

void	kill_process(void)
{
	write(1, "\n", 1);
	exit(0);
}

void	exec_signals(void)
{
	signal(SIGINT, handler_exec);
	signal(SIGQUIT, handler_exec);
}

void	non_exec_signals(void)
{
	signal(SIGINT, handler_non_exec);
	signal(SIGQUIT, SIG_IGN);
}
