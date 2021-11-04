/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:22:46 by fbafica           #+#    #+#             */
/*   Updated: 2021/11/03 15:45:22 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	is_cloded(int *sing, int *doub, char *who_first)
{
	if (*sing == 2)
	{
		if (*who_first == 's' && *doub == 1)
			*doub = 0;
		if (*who_first == 's')
			*who_first = '-';
		*sing = 0;
	}
	if (*doub == 2)
	{
		if (*who_first == 'd' && *sing == 1)
			*sing = 0;
		if (*who_first == 'd')
			*who_first = '-';
		*doub = 0;
	}
}

static void	is_quote(int *sing, int *doub, char *who_first, char c)
{
	if (c == "'"[0])
	{
		if (*who_first == '-')
			*who_first = 's';
		++*sing;
	}
	if (c == '"')
	{
		if (*who_first == '-')
			*who_first = 'd';
		++*doub;
	}
}

int	quotes_check(char *input)
{
	int		sing;
	int		doub;
	char	who_first;
	int		i;

	sing = 0;
	doub = 0;
	who_first = '-';
	i = 0;
	while (input[i] != '\0')
	{
		is_quote(&sing, &doub, &who_first, input[i]);
		is_cloded(&sing, &doub, &who_first);
		++i;
	}
	if (sing + doub != 0)
		return (0);
	return (1);
}
