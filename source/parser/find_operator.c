/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_operator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 21:05:03 by fbafica           #+#    #+#             */
/*   Updated: 2021/11/03 14:41:09 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_pipe_operator(char **tokens)
{
	int	i;

	i = 0;
	while (*tokens)
	{
		if ((*tokens)[0] == '|')
			break ;
		++i;
		++tokens;
	}
	if (!*tokens)
		return (0);
	else
		return (i);
}
