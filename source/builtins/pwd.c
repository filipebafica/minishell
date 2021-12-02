/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:57:13 by fbafica           #+#    #+#             */
/*   Updated: 2021/12/01 21:52:15 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_curr_dir(void)
{
	char	*buffer;

	buffer = NULL;
	return (getcwd(buffer, 0));
}

int	pwd(void)
{
	char	*curr_dir;

	curr_dir = get_curr_dir();
	ft_putendl_fd(curr_dir, 1);
	free(curr_dir);
	table_insert_pair(g_minishell.loc_var, "?", "0");
	return (1);
}
