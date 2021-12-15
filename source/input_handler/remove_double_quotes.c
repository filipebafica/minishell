/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_double_quotes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:25:54 by fbafica           #+#    #+#             */
/*   Updated: 2021/12/15 17:11:21 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	remove_quote(char **token)
{
	int		first;
	int		last;
	char	*tmp_1;
	char	*tmp_2;
	char	*tmp_3;

	first = ft_strchrlen(*token, '"');
	last = ft_strrchrlen(*token, '"');
	tmp_1 = ft_substr(*token, 0, first);
	tmp_2 = ft_substr(*token, first + 1, last - first - 1);
	tmp_3 = ft_strjoin(tmp_1, tmp_2);
	if (tmp_1)
		free(tmp_1);
	tmp_1 = ft_strdup(*token + last + 1);
	free(*token);
	*token = ft_strjoin(tmp_3, tmp_1);
	if (tmp_1)
		free(tmp_1);
	if (tmp_2)
		free(tmp_2);
	if (tmp_3)
		free(tmp_3);
}

static int	open_with_double(char *token)
{
	int	i;

	i = 0;
	while (token[i] != '\0')
	{
		if (token[i] == '"')
			return (1);
		if (token[i] == "'"[0])
			break ;
		++i;
	}
	return (0);
}

void	remove_double_quotes(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		while (open_with_double(tokens[i]) && !ft_strchr(tokens[i], '|') && \
		!ft_strchr(tokens[i], '<') && !ft_strchr(tokens[i], '>'))
			remove_quote(&tokens[i]);
		++i;
	}
}
