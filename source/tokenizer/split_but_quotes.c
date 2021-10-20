/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_but_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:36:21 by fbafica           #+#    #+#             */
/*   Updated: 2021/10/20 17:26:57 by fbafica          ###   ########.fr       */
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

static void	split_str(char *s, char **splited, int tokens)
{
	int		i;
	int		start;
	int		end;

	start = 0;
	end = 0;
	i = 0;
	while (i < tokens)
	{
		adjust_start_end(s, &start, &end);
		check_quotes(s, &end);
		if (s[end] == ' ' || s[end] == '\0')
		{
			splited[i] = ft_substr(s, start, (end - start));
			start = end + 1;
			++i;
		}
		end++;
	}
	splited[tokens] = (char *) '\0';
}

static int	get_tokens(char *s)
{
	int		tokens;
	char	who_opened;

	tokens = 0;
	while (*s)
	{
		if (*s == '"' || *s == "'"[0])
		{
			who_opened = *s;
			while (*++s != who_opened)
				;
		}
		if ((*s != ' ' && *(s + 1) == ' ') || (*s != ' ' && *(s + 1) == '\0'))
			tokens++;
		s++;
	}
	return (tokens);
}

char	**split_but_quotes(char *s)
{
	int		tokens;
	char	**splited;

	tokens = get_tokens(s);
	splited = malloc(sizeof(char *) * (tokens + 1));
	split_str(s, splited, tokens);
	return (splited);
}
