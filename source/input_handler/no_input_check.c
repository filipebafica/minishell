/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_input_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:08:09 by fbafica           #+#    #+#             */
/*   Updated: 2021/11/15 18:18:01 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	no_input_check(char *input)
{
	int	i;

	if (!ft_strcmp(input, ""))
		return (1);
	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] != ' ')
			return (0);
		++i;
	}
	return (1);
}
