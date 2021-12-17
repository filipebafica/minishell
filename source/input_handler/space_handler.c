/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:45:03 by fbafica           #+#    #+#             */
/*   Updated: 2021/12/17 19:01:11 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	add_space(char **input, int index)
{
	char	*frst_half;
	char	*scnd_half;
	char	*tmp;

	if ((*input)[index + 1] != ' ' && (*input)[index + 1] != '\0')
		++index;
	tmp = ft_substr(*input, 0, index);
	frst_half = ft_strjoin(tmp, " ");
	free(tmp);
	scnd_half = ft_substr(*input, index, ft_strlen(*input) - index);
	tmp = ft_strdup(*input);
	free(*input);
	*input = ft_strjoin(frst_half, scnd_half);
	free(tmp);
	free(frst_half);
	free(scnd_half);
}

static int	is_inside_quotes(char *input, int index)
{
	char	*tmp;
	int		check;

	tmp = ft_substr(input, 0, index);
	check = quotes_check(tmp);
	free(tmp);
	if (!check)
		return (1);
	return (0);
}

void	space_handler(char **input)
{
	char	*set;
	int		i;
	int		j;

	set = "><|";
	i = 1;
	while ((*input)[i] != '\0')
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (!is_inside_quotes(*input, i) && (((*input)[i - 1] != ' ' && \
			(*input)[i] == set[j]) || ((*input)[i + 1] != ' ' \
			&& (*input)[i + 1] != '\0' && (*input)[i] == set[j])))
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
