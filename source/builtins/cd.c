/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:45:00 by fbafica           #+#    #+#             */
/*   Updated: 2021/12/03 19:15:03 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cd(char **commands)
{
	int		error_status;
	char	*value;

	error_status = chdir(commands[1]);
	if (error_status != 0)
		error_status = 1;
	value = ft_itoa(error_status);
	table_insert_pair(g_minishell.error_status, "?", value);
	free(value);
	return (1);
}
