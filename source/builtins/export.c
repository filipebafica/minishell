/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:48:25 by fbafica           #+#    #+#             */
/*   Updated: 2021/12/15 13:05:58 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	export_func(char **commands)
{
	int	status;

	if (get_tokens_len(commands) == 1)
		status = export_sorted_vars();
	else
		status = export_var(commands);
	table_insert_pair(g_minishell.error_status, "?", "0");
	return (status);
}
