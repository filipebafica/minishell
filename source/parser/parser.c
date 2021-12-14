/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:53:28 by fbafica           #+#    #+#             */
/*   Updated: 2021/12/14 00:28:17 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_sub_len(char **tokens, int start, int len)
{
	int	sub_len;
	int	files_check;

	files_check = 1;
	sub_len = -1;
	sub_len = find_redirect_operator(tokens + start, len);
	if (sub_len >= 0)
		files_check = handle_redirect_files(tokens + start, len);
	if (!files_check)
		return (files_check);
	if (sub_len <= 0)
		sub_len = len;
	return (sub_len);
}

static int	get_sub_start(char **tokens, int start, int end)
{
	int	sub_start;

	sub_start = start;
	if (!find_redirect_operator(tokens + start, 1))
	{
		if (!find_redirect_operator(tokens + start + 1, 1))
			sub_start = end;
		else if (start + 2 <= end)
			sub_start += 2;
		else if (start + 1 <= end)
			sub_start += 1;
	}
	return (sub_start);
}

static char	**get_cmd(char **tokens, int start, int len)
{
	char	**cmd;
	int		sub_start;
	int		sub_len;

	sub_start = get_sub_start(tokens, start, len);
	sub_len = get_sub_len(tokens, start, len);
	if (sub_start != start)
		sub_len -= sub_start;
	if (sub_len < 0)
		cmd = sub_tokens(tokens, 0, 0);
	else
		cmd = sub_tokens(tokens, sub_start, sub_len);
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
