/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_end_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:57:08 by fbafica           #+#    #+#             */
/*   Updated: 2021/11/21 23:06:07 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_end_check(char *input)
{
	char	*set;
	int		len;
	int		i;

	set = "=><|";
	len = ft_strlen(input);
	i = 0;
	while (set[i] != '\0')
	{
		if (input[0] == set[i] || input[len - 1] == set[i])
			return (0);
		++i;
	}
	return (1);
}
