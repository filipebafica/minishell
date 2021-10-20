/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:45:03 by fbafica           #+#    #+#             */
/*   Updated: 2021/10/20 17:43:21 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	add_space(char *input, int index)
{
	char	*frst_half;
	char	*scnd_half;

	if (input[index + 1] != ' ' && input[index + 1] != '\0')
		++index;
	frst_half = ft_substr(input, 0, index);
	frst_half = ft_strjoin(frst_half, " ");
	scnd_half = ft_substr(input, index, ft_strlen(input) - index);
	input = ft_strjoin(frst_half, scnd_half);
}

void	space_handler(char *input)
{
	char	*set;
	int		i;
	int		j;

	set = "><|";
	i = 1;
	while (input[i] != '\0')
	{
		j = 0;
		while (set[j] != '\0')
		{
			if ((input[i - 1] != ' ' && input[i] == set[j]) || \
			(input[i + 1] != ' ' && input[i + 1] != '\0' && \
			input[i] == set[j]))
			{
				add_space(input, i);
				++i;
				space_handler(input);
			}
			++j;
		}
		++i;
	}
}
