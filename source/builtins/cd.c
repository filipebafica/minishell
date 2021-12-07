/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:45:00 by fbafica           #+#    #+#             */
/*   Updated: 2021/12/07 13:58:20 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_old_pwd(void)
{
	char	*curr_dir;

	curr_dir = get_curr_dir();
	table_insert_pair(g_minishell.env_var, "OLDPWD", curr_dir);
	free(curr_dir);
}

int	cd(char **commands)
{
	int		error_status;
	char	*value;
	char	*curr_dir;

	if (get_tokens_len(commands) > 2)
	{
		ft_putstr_fd("cd: too many arguments\n", 2);
		table_insert_pair(g_minishell.error_status, "?", "1");
		return (1);
	}
	handle_old_pwd();
	if (!ft_strcmp(commands[1], "~"))
		error_status = chdir(search_a_key(g_minishell.env_var, "HOME"));
	else
		error_status = chdir(commands[1]);
	if (error_status != 0)
		error_status = 1;
	value = ft_itoa(error_status);
	curr_dir = get_curr_dir();
	table_insert_pair(g_minishell.error_status, "?", value);
	table_insert_pair(g_minishell.env_var, "PWD", curr_dir);
	free(value);
	free(curr_dir);
	return (1);
}
