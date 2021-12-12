/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_signals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 21:47:11 by fbafica           #+#    #+#             */
/*   Updated: 2021/12/12 00:26:54 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handler(int signum)
{
	if (signum == SIGINT)
	{
		table_insert_pair(g_minishell.error_status, "?", "130");
		write(1, "\n", 1);
		exit(130);
	}
}

void	here_doc_signals(void)
{
	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
}
