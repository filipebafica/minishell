/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_end_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:57:08 by fbafica           #+#    #+#             */
/*   Updated: 2021/12/14 01:58:38 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	validate_end(char *input, int position)
{
	int	i;

	i = 1;
	while (input[position + i] != '\0')
	{
		if (input[position + i] && (input[position + i] != ' ' \
		|| input[position + i] != '\n'))
			return (1);
		++i;
	}
	return (0);
}

int	end_check(char *input)
{
	char	*set;
	int		position;
	int		chr_len;
	int		i;

	set = "><|";
	position = -1;
	chr_len = -1;
	i = 0;
	while (set[i] != '\0')
	{
		if (ft_strchr(input, set[i]))
			chr_len = ft_strrchrlen(input, set[i]);
		if (chr_len > position)
			position = chr_len;
		++i;
	}
	if (position < 0)
		return (1);
	return (validate_end(input, position));
}

int	init_check(char *input)
{
	char	*set;
	int		i;

	set = "|";
	i = 0;
	while (set[i] != '\0')
	{
		if (input[0] == set[i])
			return (0);
		++i;
	}
	return (1);
}
