/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:53:28 by fbafica           #+#    #+#             */
/*   Updated: 2021/12/14 22:20:25 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	check_bad_tokens(char ***cmd)
{
	int	op;

	while (find_redirect_operator(*cmd, get_tokens_len(*cmd)) >= 0)
	{
		op = find_redirect_operator(*cmd, get_tokens_len(*cmd));
		if (op >= 0)
		{
			delete_a_token(cmd, op);
			if (find_redirect_operator(*cmd + op, 1) < 0)
				delete_a_token(cmd, op);
		}
	}
}

static int	handle_files(char **tokens, int start, int len)
{
	int	status;

	status = 1;
	if (find_redirect_operator(tokens + start, len) >= 0)
		redirect_parser(&status, tokens + start, len);
	return (status);
}

static char	**get_cmd(char **tokens, int start, int len)
{
	char	**cmd;
	int		files;

	files = handle_files(tokens, start, len);
	if (!files)
		return (sub_tokens(tokens, 0, 0));
	cmd = sub_tokens(tokens, start, len);
	check_bad_tokens(&cmd);
	return (cmd);
}

static int	get_len(char **tokens, int tokens_len, int start)
{
	int	len;

	len = find_pipe_operator(tokens + start, tokens_len - start);
	if (!len)
		len = tokens_len - start;
	return (len);
}

int	parser(char **tokens, int tokens_len)
{
	int		status;
	int		start;
	int		len;
	char	**cmd;

	status = 1;
	start = 0;
	while (start < tokens_len && status)
	{
		create_pipe(find_pipe_operator(tokens + start, tokens_len - start));
		len = get_len(tokens, tokens_len, start);
		cmd = get_cmd(tokens, start, len);
		status = exec(cmd, tokens);
		free_tokens(cmd);
		replace_std_fd(g_minishell.std_fd);
		start += len + 1;
	}
	return (status);
}
