/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_non_builtin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 21:58:30 by fbafica           #+#    #+#             */
/*   Updated: 2021/11/24 21:59:17 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_non_builtin(char **commands)
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
