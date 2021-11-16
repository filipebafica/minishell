/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:53:28 by fbafica           #+#    #+#             */
/*   Updated: 2021/11/16 19:29:59 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	parse_pipe_args(char **tokens, int tokens_len)
{
	int		end;
	int		start;
	int		status;
	char	**commands;
	int		std_fd[2];

	save_std_fd(std_fd);
	start = 0;
	while (1)
	{
		end = find_pipe_operator(tokens + start);
		manage_pipe(end);
		if (!end)
			end = tokens_len;
		commands = sub_tokens(tokens, start, end);
		status = exec(commands);
		free_tokens(commands);
		start = end + 1;
		restore_std_fd(std_fd);
		if (!status || start > tokens_len)
			break ;
	}
	return (status);
}

int	parser(char **tokens)
{
	int	status;

	if (find_pipe_operator(tokens))
		status = parse_pipe_args(tokens, get_tokens_len(tokens));
	else
		status = exec(tokens);
	return (status);
}
