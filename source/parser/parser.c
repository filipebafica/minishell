/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:53:28 by fbafica           #+#    #+#             */
/*   Updated: 2021/11/22 23:36:12 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parser(char **tokens, int tokens_len)
{
	int	status;
	int	std_fd[2];

	save_std_fd(std_fd);
	status = exec(tokens, tokens_len, std_fd);
	return (status);
}
