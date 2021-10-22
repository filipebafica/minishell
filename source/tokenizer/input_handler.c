/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:46:30 by fbafica           #+#    #+#             */
/*   Updated: 2021/10/21 23:54:59 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	input_handler(char *input)
{
	char	**tokens;
	int		i;

	if(quotes_handler(input) == 1)
	{
		space_handler(input);
		tokens = split_but_quotes(input);
		i = 0;
		while (tokens[i] != (char *)'\0')
		{
			printf("%s\n", (tokens[i]));
			++i;
		}
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
