/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:53:28 by fbafica           #+#    #+#             */
/*   Updated: 2021/11/22 00:18:53 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parser(char **tokens, int tokens_len)
{
	int	status;
	int	std_fd[2];

	save_fd(std_fd, STDIN_FILENO, STDOUT_FILENO);
	if (find_pipe_operator(tokens, tokens_len))
		status = exec_in_pipe(tokens, tokens_len, std_fd);
	else
		status = exec(tokens);
	return (status);
}
