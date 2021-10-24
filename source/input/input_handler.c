/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:46:30 by fbafica           #+#    #+#             */
/*   Updated: 2021/10/24 14:31:02 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	input_handler(char *input)
{
	char	**tokens;

	if (quotes_check(input) == 1)
	{
		space_handler(&input);
		tokens = split_but_quotes(input);
		add_history(input);
		print_tokens(tokens);
		free_tokens(tokens);
	}
	else
		printf("bad syntax\n");
}
