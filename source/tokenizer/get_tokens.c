/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_but_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:36:21 by fbafica           #+#    #+#             */
/*   Updated: 2021/10/24 19:00:19 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	adjust_start_end(char *s, int *start, int *end)
{
	while (s[*start] == ' ')
		(*start)++;
	if (*start > *end)
		*end = *start;
}

static void	check_quotes(char *s, int *end)
{
	char	who_opened;

	if (s[*end] == '"' || s[*end] == "'"[0])
	{
		who_opened = s[*end];
		while (s[++*end] != who_opened)
			;
	}
}

static void	split_str(char *s, char **tokens, int num_tokens)
{
	int		i;
	int		start;
	int		end;

	start = 0;
	end = 0;
	i = 0;
	while (i < num_tokens)
	{
		adjust_start_end(s, &start, &end);
		check_quotes(s, &end);
		if (s[end] == ' ' || s[end] == '\0')
		{
			tokens[i] = ft_substr(s, start, (end - start));
			start = end + 1;
			++i;
		}
		end++;
	}
	tokens[num_tokens] = (char *) '\0';
}

static int	get_num_tokens(char *s)
{
	int		num_tokens;
	char	who_opened;

	num_tokens = 0;
	while (*s)
	{
		if (*s == '"' || *s == "'"[0])
		{
			who_opened = *s;
			while (*++s != who_opened)
				;
		}
		if ((*s != ' ' && *(s + 1) == ' ') || (*s != ' ' && *(s + 1) == '\0'))
			num_tokens++;
		s++;
	}
	return (num_tokens);
}

char	**get_tokens(char *s)
{
	int		num_tokens;
	char	**tokens;

	num_tokens = get_num_tokens(s);
	tokens = malloc(sizeof(char *) * (num_tokens + 1));
	split_str(s, tokens, num_tokens);
	return (tokens);
}
