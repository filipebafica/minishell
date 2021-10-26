/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_shell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:46:30 by fbafica           #+#    #+#             */
/*   Updated: 2021/10/25 21:29:08 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	valid_input(char *input)
{
	char	**tokens;
	int		status;

	space_handler(&input);
	tokens = get_tokens(input);
	status = launcher(tokens);
	free_tokens(tokens);
	return (status);
}

static int	invalid_input(void)
{
	printf("bad syntax\n");
	return (1);
}

int	run_shell(void)
{
	char	*input;

	input = readline("$");
	add_history(input);
	if (quotes_check(input) == 0)
		return (invalid_input());
	else
		return (valid_input(input));
}
