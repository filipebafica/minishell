/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 13:07:00 by fbafica           #+#    #+#             */
/*   Updated: 2021/11/16 19:32:05 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	manage_pipe(int is_pipe)
{
	static int	tmp_fd;
	int			new_fd[2];

	dup2(tmp_fd, STDIN_FILENO);
	if (tmp_fd)
	{
		close(tmp_fd);
		tmp_fd = 0;
	}
	if (!is_pipe)
		return ;
	pipe(new_fd);
	dup2(new_fd[1], STDOUT_FILENO);
	close(new_fd[1]);
	tmp_fd = dup(new_fd[0]);
	close(new_fd[0]);
}

void	restore_std_fd(int *std_fd)
{
	dup2(std_fd[IN], STDIN_FILENO);
	dup2(std_fd[OUT], STDOUT_FILENO);
}

void	save_std_fd(int *std_fd)
{
	std_fd[IN] = dup(STDIN_FILENO);
	std_fd[OUT] = dup(STDOUT_FILENO);
}
