/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:40:49 by fbafica           #+#    #+#             */
/*   Updated: 2021/11/30 22:51:51 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**get_path_tokens(void)
{
	char	*path_var;
	char	**path_tokens;

	path_var = search_a_key(g_minishell.env_var, "PATH");
	path_tokens = ft_split(path_var, ':');
	return (path_tokens);
}

char	*get_command_and_path(char *command)
{
	struct stat	sb;
	char		**path_tokens;
	char		*full_command;
	char		*tmp;
	int			i;

	path_tokens = get_path_tokens();
	i = 0;
	while (path_tokens[i])
	{
		tmp = ft_strjoin(path_tokens[i], "/");
		full_command = ft_strjoin(tmp, command);
		free (tmp);
		if (!stat(full_command, &sb) && sb.st_mode & S_IXUSR)
		{
			free_tokens(path_tokens);
			return (full_command);
		}
		free (full_command);
		++i;
	}
	free_tokens(path_tokens);
	return (command);
}
