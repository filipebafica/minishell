/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:53:28 by fbafica           #+#    #+#             */
/*   Updated: 2021/11/01 20:08:39 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parser(char **tokens)
{
	int		pipe_index;
	int		status;
	int		tokens_len;
	char	**command;

	pipe_index = find_pipe(tokens);
	if (pipe_index)
	{
		command = sub_tokens(tokens, 0, pipe_index);
		init_pipe(command);
		free_tokens(command);
	}
	else
		status = exec(tokens);
	if (pipe_index > 0)
	{
		tokens_len = get_tokens_len(tokens);
		command = sub_tokens(tokens, pipe_index + 1, tokens_len + 1);
		parser(command);
		free_tokens(command);
	}
	return (status);
}
