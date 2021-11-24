/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:08:49 by fbafica           #+#    #+#             */
/*   Updated: 2021/11/24 15:09:01 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	exec_non_builtin(char **commands)
{
	int		pid;
	char	*command_and_path;

	pid = fork();
	if (pid == 0)
	{
		command_and_path = get_command_and_path(*commands);
		execve(command_and_path, commands, 0);
		free(command_and_path);
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
	int		cmd_len;
	int		sub_cmd_len;
	int		start;
	int		status;
	char	**commands;

	start = 0;
	while (start < tokens_len && status)
	{
		sub_cmd_len = 0;
		cmd_len = find_pipe_operator(tokens + start, tokens_len - start);
		create_pipe(cmd_len);
		if (!cmd_len)
			cmd_len = tokens_len - start;
		if (redirect(tokens + start, cmd_len))
			sub_cmd_len = find_redirect_operator(tokens + start, cmd_len);
		if (!sub_cmd_len)
			sub_cmd_len = cmd_len;
		commands = sub_tokens(tokens, start, sub_cmd_len);
		status = select_exec_type(commands);
		free_tokens(commands);
		replace_std_fd(saved_fd);
		start += cmd_len + 1;
	}
	return (status);
}
