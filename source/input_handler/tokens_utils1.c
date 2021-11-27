/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:20:35 by fbafica           #+#    #+#             */
/*   Updated: 2021/11/26 18:31:55 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**join_tokens(char **tokens1, char **tokens2)
{
	char	**new_tokens;
	int		len_1;
	int		len_2;
	int		i;

	len_1 = get_tokens_len(tokens1);
	len_2 = get_tokens_len(tokens2);
	new_tokens = malloc(sizeof(char *) * (1 + len_1 + len_2));
	i = 0;
	while (i < len_1)
	{
		new_tokens[i] = ft_strdup(tokens1[i]);
		++i;
	}
	i = 0;
	while (i < len_2)
	{
		new_tokens[len_1 + i] = ft_strdup(tokens2[i]);
		++i;
	}
	new_tokens[len_1 + len_2] = (char *) '\0';
	return (new_tokens);
}

char	**sub_tokens(char **tokens, int start, int len)
{
	char	**new_tokens;
	int		i;

	new_tokens = malloc(sizeof(char *) * (1 + len));
	i = 0;
	while (i < len)
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
		ft_printf("%s\n", (tokens[i]));
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
