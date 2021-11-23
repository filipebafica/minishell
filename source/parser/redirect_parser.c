/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:45:04 by fbafica           #+#    #+#             */
/*   Updated: 2021/11/22 22:24:21 by fbafica          ###   ########.fr       */
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

// static void	redirect_in(int flags)
// {
// }

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
	int	first_opertaor;
	int	i;

	first_opertaor = find_redirect_operator(tokens, tokens_len);
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
		++i;
	}
	return (first_opertaor);
}
