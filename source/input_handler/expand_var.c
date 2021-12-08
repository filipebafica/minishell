/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:45:04 by fbafica           #+#    #+#             */
/*   Updated: 2021/12/08 20:17:06 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_var_len(char *token, int start)
{
	int	len;
	int	i;

	len = ft_strlen(token);
	if (len > 1 && (token[len - 1] == "'"[0] || token[len - 1] == '"'))
		--len;
	i = 0;
	while (start + i < len)
	{
		if (token[start + i] == ' ' || token[start + i] == "'"[0] \
		|| token[start + i] == '"')
			break ;
		++i;
	}
	return (i);
}

static void	replace_var(char **token, int var_start)
{
	int		var_len;
	char	*tmp_1;
	char	*tmp_2;
	char	*tmp_3;
	char	*key;

	var_len = get_var_len(*token, var_start + 1);
	tmp_1 = ft_substr(*token, 0, var_start);
	key = ft_substr(*token, var_start + 1, var_len);
	tmp_2 = ft_strjoin(tmp_1, get_value_by_key(key));
	tmp_3 = ft_strdup(*token + var_start + 1 + var_len);
	free(*token);
	*token = ft_strjoin(tmp_2, tmp_3);
	if (key)
		free(key);
	if (tmp_1)
		free(tmp_1);
	if (tmp_2)
		free(tmp_2);
	if (tmp_3)
		free(tmp_3);
}

static int	open_with_single(char *token)
{
	int	i;

	i = 0;
	while (token[i] != '\0')
	{
		if (token[i] == "'"[0])
			return (1);
		if (token[i] == '"')
			break ;
		++i;
	}
	return (0);
}

static int	check_expand_var(char *token, int var_start)
{
	if (!open_with_single(token) && token[var_start + 1] != ' ' \
	&& token[var_start + 1] != '\0')
		return (1);
	return (0);
}

void	expand_var(char **tokens)
{
	int		i;
	int		var_start;

	i = 0;
	while (tokens[i])
	{
		if (ft_strchr(tokens[i], '$'))
		{
			var_start = ft_strchrlen(tokens[i], '$');
			if (check_expand_var(tokens[i], var_start))
				replace_var(&(tokens[i]), var_start);
		}
		++i;
	}
}
