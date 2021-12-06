/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:45:04 by fbafica           #+#    #+#             */
/*   Updated: 2021/12/06 18:46:39 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*check_key(char *key)
{
	char	*value;

	value = search_a_key(g_minishell.env_var, key);
	if (!value)
		value = search_a_key(g_minishell.loc_var, key);
	if (!value)
		value = search_a_key(g_minishell.error_status, key);
	if (value)
		return (value);
	else
		return (NULL);
}

void	expand_var(char **tokens)
{
	char	*value;
	int		i;

	i = 0;
	while (tokens[i])
	{
		if (tokens[i][0] == '$')
		{
			value = check_key(tokens[i] + 1);
			if (value)
				replace_a_token(&tokens, i, value);
			else
				replace_a_token(&tokens, i, "");
		}
		++i;
	}
}
