/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:08:49 by fbafica           #+#    #+#             */
/*   Updated: 2021/11/23 16:39:01 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	exec_non_builtin(char **commands)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		execve(*commands, commands, 0);
		exit(EXIT_FAILURE);
	}
	else
		wait(NULL);
	return (1);
}

static int	exec_builtin(char **commands)
{
	if (!ft_strcmp(*commands, "echo"))
		return (echo(commands));
	if (!ft_strcmp(*commands, "cd"))
		return (cd(commands));
	if (!ft_strcmp(*commands, "pwd"))
		return (pwd());
	if (!ft_strcmp(*commands, "exit"))
		return (exit_shell());
	if (!ft_strcmp(*commands, "env"))
		return (env());
	if (!ft_strcmp(*commands, "export"))
		return (export_var(commands));
	if (!ft_strcmp(*commands, "unset"))
		return (unset_var(commands));
	return (1);
}

static int	is_builtin(char **commands)
{
	if (!ft_strcmp(*commands, "echo"))
		return (1);
	if (!ft_strcmp(*commands, "cd"))
		return (1);
	if (!ft_strcmp(*commands, "pwd"))
		return (1);
	if (!ft_strcmp(*commands, "export"))
		return (1);
	if (!ft_strcmp(*commands, "unset"))
		return (1);
	if (!ft_strcmp(*commands, "env"))
		return (1);
	if (!ft_strcmp(*commands, "exit"))
		return (1);
	return (0);
}

static int	select_exec_type(char **commands)
{
	if (is_builtin(commands))
		return (exec_builtin(commands));
	else
		return (exec_non_builtin(commands));
}

int	exec(char **tokens, int tokens_len, int *saved_fd)
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
		if (redirect(tokens + start, command_len))
			command_len = find_redirect_operator(tokens + start, command_len);
		commands = sub_tokens(tokens, start, command_len);
		status = select_exec_type(commands);
		free_tokens(commands);
		replace_std_fd(saved_fd);
		start += command_len + 1;
	}
	return (status);
}
