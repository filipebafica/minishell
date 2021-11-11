/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:08:49 by fbafica           #+#    #+#             */
/*   Updated: 2021/11/11 19:08:34 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	exec_non_builtin(char **commands)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		execve(*commands, commands, NULL);
		exit(0);
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
	return (1);
}

int	exec(char **commands)
{
	if (is_builtin(commands))
		return (exec_builtin(commands));
	else
		return (exec_non_builtin(commands));
}
