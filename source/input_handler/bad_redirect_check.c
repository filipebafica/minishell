/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bad_redirect_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 23:07:28 by fbafica           #+#    #+#             */
/*   Updated: 2021/12/14 01:07:35 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	find_redirect_charact(char *input)
{
	char	*set;
	int		i;
	int		j;

	set = "><";
	i = 0;
	while (set[i] != '\0')
	{
		j = 0;
		while (input[j] != '\0')
		{
			if (set[i] == input[j])
				return (j);
			++j;
		}
		++i;
	}
	return (0);
}

int	bad_redirect_check(char *input)
{
	int	position;

	position = find_redirect_charact(input);
	while (position > 0)
	{
		if (input[position] == '>' && input[position + 1] == '<')
			return (0);
		else if (input[position] == '<' && input[position + 1] == '>')
			return (0);
		else if (input[position] == '>' && input[position + 1] == '|')
			return (0);
		else if (input[position] == '<' && input[position + 1] == '|')
			return (0);
		position = find_redirect_charact(input + position);
	}
	return (1);
}
