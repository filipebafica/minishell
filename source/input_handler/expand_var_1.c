/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:15:10 by fbafica           #+#    #+#             */
/*   Updated: 2021/12/10 19:54:51 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_vars(char *token)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (token[i] != '\0')
	{
		if (token[i] == '$')
			++j;
		++i;
	}
	return (j);
}

void	expand_var(char **tokens)
{
	int		i;
	int		j;
	int		num_vars;
	int		var_start;

	i = 0;
	while (tokens[i])
	{
		j = 0;
		num_vars = count_vars(tokens[i]);
		var_start = 0;
		while (j < num_vars)
		{
			var_start = ft_strchrlen(tokens[i], '$') + 1;
			if (check_expand_var(tokens[i], var_start))
				replace_var(&(tokens[i]), var_start - 1);
			++j;
		}
		++i;
	}
}
