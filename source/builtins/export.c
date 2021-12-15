/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:48:25 by fbafica           #+#    #+#             */
/*   Updated: 2021/12/14 23:55:31 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	export_func(char **commands)
{
	int	status;

	if (!ft_strcmp(commands[1], ""))
		status = export_sorted_vars();
	else
		status = export_var(commands);
	table_insert_pair(g_minishell.error_status, "?", "0");
	return (status);
}
