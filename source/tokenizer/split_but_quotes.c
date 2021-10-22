/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_but_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:36:21 by fbafica           #+#    #+#             */
/*   Updated: 2021/10/21 23:16:06 by fbafica          ###   ########.fr       */
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

static void	split_str(char *s, char **splited, int num_tokens)
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
			splited[i] = ft_substr(s, start, (end - start));
			start = end + 1;
			++i;
		}
		end++;
	}
	splited[num_tokens] = (char *) '\0';
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

char	**split_but_quotes(char *s)
{
	int		num_tokens;
	char	**splited;

	num_tokens = get_num_tokens(s);
	splited = malloc(sizeof(char *) * (num_tokens + 1));
	split_str(s, splited, num_tokens);
	return (splited);
}
