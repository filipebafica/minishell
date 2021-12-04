/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:27:50 by fbafica           #+#    #+#             */
/*   Updated: 2021/12/03 22:14:02 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_singint(int signal)
{
	char	*prompt;

	(void)signal;
	if (isatty(STDIN_FILENO))
	{
		prompt = create_prompt();
		ft_printf("\n%s", prompt);
		free(prompt);
	}
}

void	define_signals(void)
{
	signal(SIGINT, handle_singint);
	signal(SIGQUIT, SIG_IGN);
}
