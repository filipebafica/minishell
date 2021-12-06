/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:45:00 by fbafica           #+#    #+#             */
/*   Updated: 2021/12/04 21:32:20 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cd(char **commands)
{
	int		error_status;
	char	*value;
	char	*curr_dir;

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
