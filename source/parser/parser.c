/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:53:28 by fbafica           #+#    #+#             */
/*   Updated: 2021/11/16 23:16:46 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	parse_pipe_args(char **tokens, int tokens_len)
{
	int		command_len;
	int		start;
	int		status;
	char	**commands;
	int		std_fd[2];

	save_std_fd(std_fd);
	start = 0;
	while (1)
	{
		command_len = find_pipe_operator(tokens + start);
		manage_pipe(command_len);
		if (!command_len)
			command_len = tokens_len - start;
		commands = sub_tokens(tokens, start, command_len);
		status = exec(commands);
		free_tokens(commands);
		start += command_len + 1;
		restore_std_fd(std_fd);
		if (!status || start > tokens_len)
			break ;
	}
	return (status);
}

int	parser(char **tokens)
{
	int	status;
	int	len;

	len = get_tokens_len(tokens);
	if (find_pipe_operator(tokens))
		status = parse_pipe_args(tokens, len);
	else
		status = exec(tokens);
	return (status);
}
