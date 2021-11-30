/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:45:04 by fbafica           #+#    #+#             */
/*   Updated: 2021/11/29 20:57:28 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	redirect_out(char *file_name, int flags)
{
	int	file;

	file = open(file_name, flags, 0777);
	if (file >= 0)
	{
		dup2(file, STDOUT_FILENO);
		close(file);
	}
	else
	{
		perror("error");
		return (0);
	}
	return (1);
}

static int	redirect_in(char *file_name, int flags)
{
	int	file;

	file = open(file_name, flags);
	if (file >= 0)
	{
		dup2(file, STDIN_FILENO);
		close(file);
	}
	else
	{
		perror("error");
		return (0);
	}
	return (1);
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
	return (-1);
}

int	handle_redirect_files(char **tokens, int tokens_len)
{
	int	i;
	int	check;

	i = 0;
	while (i <= tokens_len)
	{
		if (!ft_strcmp(tokens[i], ">") && ft_strcmp(tokens[i + 1], ">"))
			check = redirect_out(tokens[i + 1], O_RDWR | O_CREAT | O_TRUNC);
		else if (!ft_strcmp(tokens[i], ">") && !ft_strcmp(tokens[i + 1], ">"))
		{
			check = redirect_out(tokens[i + 2], O_RDWR | O_CREAT | O_APPEND);
			++i;
		}
		else if (!ft_strcmp(tokens[i], "<") && ft_strcmp(tokens[i + 1], "<"))
			check = redirect_in(tokens[i + 1], O_RDONLY);
		else if (!ft_strcmp(tokens[i], "<") && !ft_strcmp(tokens[i + 1], "<"))
		{
			check = here_doc(tokens[i + 2]);
			++i;
		}
		if (!check)
			return (check);
		++i;
	}
	return (1);
}
