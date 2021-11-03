/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 13:07:00 by fbafica           #+#    #+#             */
/*   Updated: 2021/11/02 13:48:37 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	create_pipe(void)
{
	static int	tmp_fd;
	int			new_fd[2];

	if (tmp_fd == 1)
	{
		tmp_fd = dup(new_fd[OUT]);
		close(new_fd[IN]);
		close(new_fd[OUT]);
		pipe(new_fd);
		dup2(tmp_fd, new_fd[IN]);
	}
	else
		pipe(new_fd);
	dup2(new_fd[IN], STDIN_FILENO);
	dup2(new_fd[OUT], STDOUT_FILENO);
	tmp_fd = 1;
}

static void	save_std_fd(int *std_fd)
{
	std_fd[IN] = dup(STDIN_FILENO);
	std_fd[OUT] = dup(STDOUT_FILENO);
}

void	init_pipe(void)
{
	int	std_fd[2];

	save_std_fd(std_fd);
	create_pipe();
}
