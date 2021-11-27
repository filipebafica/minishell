/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_shell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:46:30 by fbafica           #+#    #+#             */
/*   Updated: 2021/11/26 22:09:21 by fbafica          ###   ########.fr       */
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
	status = parser(tokens, get_tokens_len(tokens));
	free(mod_input);
	free_tokens(tokens);
	return (status);
}

static int	invalid_input(void)
{
	ft_putendl_fd("bad syntax", 1);
	return (1);
}

int	run_shell(void)
{
	char	*input;
	char	*prompt;
	char	*curr_dir;
	int		status;

	curr_dir = get_curr_dir();
	prompt = ft_strjoin(curr_dir, "$ ");
	input = readline(prompt);
	add_history(input);
	if (no_input_check(input))
		status = 1;
	else if (!quotes_check(input) || !init_end_check(input) \
	|| !bad_redirect_check(input))
		status = invalid_input();
	else
		status = valid_input(input);
	free(input);
	free(curr_dir);
	free(prompt);
	return (status);
}
