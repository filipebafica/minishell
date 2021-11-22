/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 13:07:00 by fbafica           #+#    #+#             */
/*   Updated: 2021/11/22 00:11:25 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	create_pipe(int is_pipe)
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

int	exec_in_pipe(char **tokens, int tokens_len, int *saved_fd)
{
	int		command_len;
	int		start;
	int		status;
	char	**commands;

	start = 0;
	while (start < tokens_len && status)
	{
		command_len = find_pipe_operator(tokens + start, tokens_len - start);
		create_pipe(command_len);
		if (!command_len)
			command_len = tokens_len - start;
		command_len = command_len - redirect(tokens + start, command_len);
		commands = sub_tokens(tokens, start, command_len);
		status = exec(commands);
		free_tokens(commands);
		replace_std_fd(saved_fd);
		start += command_len + 1;
	}
	return (status);
}
