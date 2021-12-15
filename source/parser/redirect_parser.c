/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:45:04 by fbafica           #+#    #+#             */
/*   Updated: 2021/12/14 22:20:33 by fbafica          ###   ########.fr       */
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
		table_insert_pair(g_minishell.error_status, "?", "1");
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
		table_insert_pair(g_minishell.error_status, "?", "1");
		return (0);
	}
	return (1);
}

int	find_redirect_operator(char **tokens, int tokens_len)
{
	char	op_1;
	char	op_2;
	int		i;

	op_1 = '>';
	op_2 = '<';
	i = 0;
	while (tokens[i] && i < tokens_len)
	{
		if (op_1 == tokens[i][0] || op_2 == tokens[i][0])
			return (i);
		++i;
	}
	return (-1);
}

int	redirect_parser(int *status, char **tokens, int tokens_len)
{
	int	i;

	i = 0;
	while (i <= tokens_len)
	{
		if (!ft_strcmp(tokens[i], ">") && ft_strcmp(tokens[i + 1], ">"))
			*status = redirect_out(tokens[i + 1], O_RDWR | O_CREAT | O_TRUNC);
		else if (!ft_strcmp(tokens[i], ">") && !ft_strcmp(tokens[i + 1], ">"))
		{
			*status = redirect_out(tokens[i + 2], O_RDWR | O_CREAT | O_APPEND);
			++i;
		}
		else if (!ft_strcmp(tokens[i], "<") && ft_strcmp(tokens[i + 1], "<"))
			*status = redirect_in(tokens[i + 1], O_RDONLY);
		else if (!ft_strcmp(tokens[i], "<") && !ft_strcmp(tokens[i + 1], "<"))
		{
			*status = here_doc(tokens[i + 2]);
			++i;
		}
		if (!*status)
			return (*status);
		++i;
	}
	return (1);
}
