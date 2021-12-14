/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bad_equal_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 21:35:57 by fbafica           #+#    #+#             */
/*   Updated: 2021/12/14 01:07:43 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	bad_equal_check(char *input)
{
	int	i;

	i = 0;
	while (input[i] != '\0')
	{
		if (i > 0 && input[i] == '=' && input[i - 1] == ' ')
			return (0);
		if (input[i] == '=' && input[i + 1] == ' ')
			return (0);
		++i;
	}
	return (1);
}
