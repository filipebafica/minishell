/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:46:30 by fbafica           #+#    #+#             */
/*   Updated: 2021/10/21 23:42:34 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	input_handler(char *input, t_command **head)
{
	char	**tokens;
	int		i;

	if(quotes_handler(input) == 1)
	{
		space_handler(input);
		tokens = split_but_quotes(input);
		feed_commands(head, tokens, tokens_len(tokens) - 1);
		i = 0;
		while (tokens[i] != (char *)'\0')
		{
			free(tokens[i]);
			++i;
		}
		free(tokens);
	}
	else
		printf("bad syntax\n");
}
