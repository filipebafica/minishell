/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:53:28 by fbafica           #+#    #+#             */
/*   Updated: 2021/11/12 22:57:24 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static int	parse_pipe_args(char **tokens)
// {
// 	int		end;
// 	int		start;
// 	int		len;
// 	int		status;
// 	char	**commands;

// 	start = 0;
// 	len = get_tokens_len(tokens);
// 	while (1)
// 	{
// 		end = find_pipe_operator(tokens + start);
// 		manage_pipe(end);
// 		if (!end)
// 			end = len;
// 		commands = sub_tokens(tokens, start, end);
// 		status = exec(commands);
// 		free_tokens(commands);
// 		start = end + 1;
// 		if (!status || start > len)
// 			break ;
// 	}
// 	return (status);
// }

int	parser(char **tokens)
{
	int	status;
	// int	std_fd[2];

	if (find_pipe_operator(tokens))
	{
		// save_std_fd(std_fd);
		// status = parse_pipe_args(tokens);
		// restore_std_fd(std_fd);
		status = 1;
	}
	else
		status = exec(tokens);
	return (status);
}
