/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:15:10 by fbafica           #+#    #+#             */
/*   Updated: 2021/12/10 16:15:31 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expand_var(char **tokens)
{
	int		i;
	int		var_start;

	i = 0;
	while (tokens[i])
	{
		var_start = 0;
		while (ft_strchr(tokens[i] + var_start, '$'))
		{
			var_start = ft_strchrlen(tokens[i] + var_start, '$') + 1;
			if (check_expand_var(tokens[i], var_start))
				replace_var(&(tokens[i]), var_start - 1);
		}
		++i;
	}
}
