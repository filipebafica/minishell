/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:45:04 by fbafica           #+#    #+#             */
/*   Updated: 2021/11/23 15:02:55 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	redirect_out(char *file_name, int flags)
{
	int	file;

	file = open(file_name, flags, 0777);
	if (file >= 0)
	{
		dup2(file, STDOUT_FILENO);
		close(file);
	}
}

static void	redirect_in(char *file_name, int flags)
{
	int	file;

	file = open(file_name, flags);
	if (file >= 0)
	{
		dup2(file, STDIN_FILENO);
		close(file);
	}
}

int	find_redirect_operator(char **tokens, int tokens_len)
{
	char	*set;
	int		i;
	int		j;

	set = "><";
	i = 0;
	while (set[i] != '\0')
	{
		j = 0;
		while (j < tokens_len)
		{
			if (set[i] == tokens[j][0])
				return (j);
			++j;
		}
		++i;
	}
	return (0);
}

int	redirect(char **tokens, int tokens_len)
{
	int	i;

	if (!find_redirect_operator(tokens, tokens_len))
		return (0);
	i = 0;
	while (i < tokens_len)
	{
		if (!ft_strcmp(tokens[i], ">") && ft_strcmp(tokens[i + 1], ">"))
			redirect_out(tokens[i + 1], O_RDWR | O_CREAT | O_TRUNC);
		else if (!ft_strcmp(tokens[i], ">") && !ft_strcmp(tokens[i + 1], ">"))
		{
			redirect_out(tokens[i + 2], O_RDWR | O_CREAT | O_APPEND);
			++i;
		}
		else if (!ft_strcmp(tokens[i], "<") && ft_strcmp(tokens[i + 1], "<"))
			redirect_in(tokens[i + 1], O_RDWR | O_CREAT);
		++i;
	}
	return (1);
}
