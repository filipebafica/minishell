/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_shell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:46:30 by fbafica           #+#    #+#             */
/*   Updated: 2021/12/12 00:03:58 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	valid_input(char *input)
{
	char	**tokens;
	char	*mod_input;
	int		status;

	mod_input = ft_strdup(input);
	space_handler(&mod_input);
	tokens = get_tokens(mod_input);
	expand_var(tokens);
	remove_double_quotes(tokens);
	status = parser(tokens, get_tokens_len(tokens));
	free(mod_input);
	free_tokens(tokens);
	return (status);
}

static int	invalid_input(void)
{
	ft_putendl_fd("bad syntax", 2);
	table_insert_pair(g_minishell.error_status, "?", "1");
	return (1);
}

char	*create_prompt(void)
{
	char	*curr_dir;
	char	*prompt;

	curr_dir = get_curr_dir();
	prompt = ft_strjoin(curr_dir, "$ ");
	free(curr_dir);
	return (prompt);
}

int	run_shell(void)
{
	char	*input;
	char	*prompt;
	int		status;

	non_exec_signals();
	prompt = create_prompt();
	input = readline(prompt);
	if (!input)
		kill_process();
	if (ft_strcmp(input, ""))
		add_history(input);
	if (no_input_check(input))
		status = 1;
	else if (!quotes_check(input) || !init_check(input) \
	|| !end_check(input) || !bad_redirect_check(input) \
	|| !bad_equal_check(input))
		status = invalid_input();
	else
		status = valid_input(input);
	free(input);
	free(prompt);
	return (status);
}
