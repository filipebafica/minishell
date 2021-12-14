/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:22:46 by fbafica           #+#    #+#             */
/*   Updated: 2021/12/14 01:07:12 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	is_closed(int *sing, int *doub, char *first_quote)
{
	if (*sing == 2)
	{
		if (*first_quote == 's' && *doub == 1)
			*doub = 0;
		if (*first_quote == 's')
			*first_quote = '-';
		*sing = 0;
	}
	if (*doub == 2)
	{
		if (*first_quote == 'd' && *sing == 1)
			*sing = 0;
		if (*first_quote == 'd')
			*first_quote = '-';
		*doub = 0;
	}
}

static void	is_quote(int *sing, int *doub, char *first_quote, char c)
{
	if (c == "'"[0])
	{
		if (*first_quote == '-')
			*first_quote = 's';
		++*sing;
	}
	if (c == '"')
	{
		if (*first_quote == '-')
			*first_quote = 'd';
		++*doub;
	}
}

int	quotes_check(char *input)
{
	int		sing;
	int		doub;
	char	first_quote;
	int		i;

	sing = 0;
	doub = 0;
	first_quote = '-';
	i = 0;
	while (input[i] != '\0')
	{
		is_quote(&sing, &doub, &first_quote, input[i]);
		is_closed(&sing, &doub, &first_quote);
		++i;
	}
	if (sing + doub != 0)
		return (0);
	return (1);
}
