/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 21:57:29 by fbafica           #+#    #+#             */
/*   Updated: 2021/12/02 13:37:02 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_builtin(char **commands)
{
	if (*commands[0] == '$')
		return (expand_var(*commands));
	else if (!ft_strcmp(*commands, "echo"))
		return (echo(commands));
	else if (!ft_strcmp(*commands, "cd"))
		return (cd(commands));
	else if (!ft_strcmp(*commands, "pwd"))
		return (pwd());
	else if (!ft_strcmp(*commands, "exit"))
		return (exit_shell(commands));
	else if (!ft_strcmp(*commands, "env"))
		return (env());
	else if (!ft_strcmp(*commands, "export"))
		return (export_func(commands));
	else if (!ft_strcmp(*commands, "unset"))
		return (unset_var(commands));
	else if (check_create_local_var(commands))
		return (create_local_vars(commands));
	return (1);
}

int	is_builtin(char **commands, int pipe_flag)
{
	if (*commands[0] == '$')
		return (1);
	else if (!ft_strcmp(*commands, "echo"))
		return (1);
	else if (!ft_strcmp(*commands, "cd"))
		return (1);
	else if (!ft_strcmp(*commands, "pwd"))
		return (1);
	else if (!ft_strcmp(*commands, "export") && !pipe_flag)
		return (1);
	else if (!ft_strcmp(*commands, "unset"))
		return (1);
	else if (!ft_strcmp(*commands, "env"))
		return (1);
	else if (!ft_strcmp(*commands, "exit") && !pipe_flag)
		return (1);
	else if (check_create_local_var(commands) && !pipe_flag)
		return (1);
	return (0);
}
