/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:46:30 by fbafica           #+#    #+#             */
/*   Updated: 2021/10/24 18:50:57 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	input_handler(char *input)
{
	char	**tokens;

	if (quotes_check(input) == 0)
	{
		printf("bad syntax\n");
		return ;
	}
	space_handler(&input);
	add_history(input);
	tokens = split_but_quotes(input);
	free_tokens(tokens);
}
