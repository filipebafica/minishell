/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:53:28 by fbafica           #+#    #+#             */
/*   Updated: 2021/11/03 00:52:17 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	pipe_args(char **tokens)
{
	int		end;
	int		start;
	int		len;
	int		status;
	char	**commands;

	start = 0;
	end = find_pipe(tokens);
	len = get_tokens_len(tokens);
	while (1)
	{
		commands = sub_tokens(tokens, start, end);
		status = exec(commands);
		free_tokens(commands);
		start = end + 1;
		if (!status || start > len)
			break ;
		end = find_pipe(tokens + start);
		if (!end)
			end = len;
	}
	return (status);
}

int	parser(char **tokens)
{
	int	status;

	if (find_pipe(tokens))
		status = pipe_args(tokens);
	else
		status = exec(tokens);
	return (status);
}
