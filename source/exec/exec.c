/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:08:49 by fbafica           #+#    #+#             */
/*   Updated: 2021/12/05 20:56:05 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	select_exec_type(char **commands, int pipe_flag)
{
	if (!*commands)
		return (1);
	else if (is_builtin(commands, pipe_flag))
		return (exec_builtin(commands));
	else
		return (exec_non_builtin(commands));
}

static int	get_sub_cmd_len(char **tokens, int cmd_len, int start)
{
	int	sub_cmd_len;
	int	files_check;

	sub_cmd_len = find_redirect_operator(tokens + start, cmd_len);
	if (sub_cmd_len >= 0)
		files_check = handle_redirect_files(tokens + start, cmd_len);
	if (!files_check)
		return (files_check);
	if (sub_cmd_len <= 0)
		sub_cmd_len = cmd_len;
	return (sub_cmd_len);
}

static int	get_cmd_len(char **tokens, int tokens_len, int start)
{
	int	cmd_len;

	cmd_len = find_pipe_operator(tokens + start, tokens_len - start);
	if (!cmd_len)
		cmd_len = tokens_len - start;
	return (cmd_len);
}

int	exec(char **tokens, int tokens_len)
{
	int		cmd_len;
	int		sub_cmd_len;
	int		start;
	int		status;
	char	**commands;

	status = 1;
	start = 0;
	while (start < tokens_len && status)
	{
		create_pipe(find_pipe_operator(tokens + start, tokens_len - start));
		cmd_len = get_cmd_len(tokens, tokens_len, start);
		sub_cmd_len = get_sub_cmd_len(tokens, cmd_len, start);
		commands = sub_tokens(tokens, start, sub_cmd_len);
		status = select_exec_type(commands, check_a_token(tokens, "|"));
		free_tokens(commands);
		replace_std_fd(g_minishell.std_fd);
		start += cmd_len + 1;
		sub_cmd_len = 0;
	}
	return (status);
}
