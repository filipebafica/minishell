/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:27:50 by fbafica           #+#    #+#             */
/*   Updated: 2021/12/09 13:47:25 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_singint_empty_line(int signum)
{
	(void)signum;
	if (isatty(STDIN_FILENO))
		ft_printf("\n");
	else
		return ;
	table_insert_pair(g_minishell.error_status, "?", "130");
}

static void	handle_singint_new_prompt(int signum)
{
	char	*prompt;

	(void)signum;
	if (isatty(STDIN_FILENO))
	{
		prompt = create_prompt();
		ft_printf("\n%s", prompt);
		free(prompt);
	}
	else
		return ;
	table_insert_pair(g_minishell.error_status, "?", "130");
}

void	kill_process(void)
{
	write(1, "\n", 1);
	exit(0);
}

void	signals_new_prompt(void)
{
	signal(SIGINT, handle_singint_new_prompt);
	signal(SIGQUIT, SIG_IGN);
}

void	signals_empty_line(void)
{
	signal(SIGINT, handle_singint_empty_line);
}
