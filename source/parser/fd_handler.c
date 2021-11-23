/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 21:56:57 by fbafica           #+#    #+#             */
/*   Updated: 2021/11/22 19:04:22 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	replace_std_fd(int *new_fd)
{
	dup2(new_fd[IN], STDIN_FILENO);
	dup2(new_fd[OUT], STDOUT_FILENO);
}

void	save_std_fd(int *fd_holder)
{
	fd_holder[IN] = dup(STDIN_FILENO);
	fd_holder[OUT] = dup(STDOUT_FILENO);
}
