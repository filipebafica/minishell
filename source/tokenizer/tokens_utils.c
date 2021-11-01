/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:20:35 by fbafica           #+#    #+#             */
/*   Updated: 2021/11/01 20:04:45 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**sub_tokens(char **tokens, int start, int end)
{
	char	**new_tokens;
	int		i;

	new_tokens = malloc(sizeof(char *) * (1 + end - start));
	i = 0;
	while (i < (end - start))
	{
		new_tokens[i] = ft_strdup(tokens[start + i]);
		++i;
	}
	new_tokens[i] = (char *) '\0';
	return (new_tokens);
}

int	get_tokens_len(char **tokens)
{
	int	i;

	i = 0;
	while (*tokens)
	{
		++i;
		++tokens;
	}
	return (i);
}

void	print_tokens(char **tokens)
{
	int	i;
	int	len;

	i = 0;
	len = get_tokens_len(tokens);
	while (i < len)
	{
		printf("%s\n", (tokens[i]));
		++i;
	}
}

void	free_tokens(char **tokens)
{
	int	i;
	int	len;

	if (!tokens)
		return ;
	i = 0;
	len = get_tokens_len(tokens);
	while (i < len)
	{
		free(tokens[i]);
		++i;
	}
	if (tokens)
		free(tokens);
}
