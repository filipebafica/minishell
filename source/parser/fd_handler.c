/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 21:56:57 by fbafica           #+#    #+#             */
/*   Updated: 2021/11/22 00:17:31 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	replace_std_fd(int *new_fd)
{
	dup2(new_fd[IN], STDIN_FILENO);
	dup2(new_fd[OUT], STDOUT_FILENO);
}

void	save_fd(int *fd_holder, int fd_in, int fd_out)
{
	fd_holder[IN] = dup(fd_in);
	fd_holder[OUT] = dup(fd_out);
}
