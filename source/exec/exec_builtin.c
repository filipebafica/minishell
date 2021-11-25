/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 21:57:29 by fbafica           #+#    #+#             */
/*   Updated: 2021/11/24 21:59:37 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_builtin(char **commands)
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

int	is_builtin(char **commands)
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
