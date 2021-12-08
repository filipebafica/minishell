/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_non_builtin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 21:58:30 by fbafica           #+#    #+#             */
/*   Updated: 2021/12/07 19:34:20 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exec_child(char **commands)
{
	char	*command_and_path;
	char	**env_var_arr;

	env_var_arr = env_var_table_to_env_var_arr();
	command_and_path = get_command_and_path(*commands);
	execve(command_and_path, commands, env_var_arr);
	perror("error");
	free(command_and_path);
	free_tokens(env_var_arr);
	exit(EXIT_FAILURE);
}

int	exec_non_builtin(char **commands)
{
	int		pid;
	int		status;
	char	*error_status;

	signals_empty_line();
	pid = fork();
	if (pid == 0)
		exec_child(commands);
	else
		waitpid(pid, &status, 0);
	if (WIFEXITED(status))
	{
		error_status = ft_itoa(WEXITSTATUS(status));
		table_insert_pair(g_minishell.error_status, "?", error_status);
		free(error_status);
	}
	return (1);
}
