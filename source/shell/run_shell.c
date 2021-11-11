/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_shell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:46:30 by fbafica           #+#    #+#             */
/*   Updated: 2021/11/11 19:17:33 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	valid_input(char *input)
{
	char	**tokens;
	int		status;

	space_handler(&input);
	tokens = get_tokens(input);
	status = parser(tokens);
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
	if (!quotes_check(input))
		status = invalid_input();
	else
		status = valid_input(input);
	free(curr_dir);
	free(prompt);
	free(input);
	return (status);
}
