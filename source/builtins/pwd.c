/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:57:13 by fbafica           #+#    #+#             */
/*   Updated: 2021/11/11 17:05:55 by fbafica          ###   ########.fr       */
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
	ft_putendl_fd(get_curr_dir(), 1);
	return (1);
}
