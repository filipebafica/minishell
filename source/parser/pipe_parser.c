/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 13:07:00 by fbafica           #+#    #+#             */
/*   Updated: 2021/11/22 23:37:53 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_pipe(int is_pipe)
{
	static int	tmp_fd;
	int			new_fd[2];

	dup2(tmp_fd, STDIN_FILENO);
	if (tmp_fd)
	{
		close(tmp_fd);
		tmp_fd = 0;
	}
	if (!is_pipe)
		return ;
	pipe(new_fd);
	dup2(new_fd[OUT], STDOUT_FILENO);
	close(new_fd[OUT]);
	tmp_fd = dup(new_fd[IN]);
	close(new_fd[IN]);
}

int	find_pipe_operator(char **tokens, int tokens_len)
{
	int	i;

	i = 0;
	while (i < tokens_len)
	{
		if (!ft_strcmp(tokens[i], "|"))
			break ;
		++i;
	}
	if (i == tokens_len)
		return (0);
	else
		return (i);
}
