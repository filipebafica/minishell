/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:46:30 by fbafica           #+#    #+#             */
/*   Updated: 2021/10/20 17:40:47 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	input_handler(char *input)
{
	char **splited_input;
	int i;

	if(quotes_handler(input) == 1)
	{
		space_handler(input);
		splited_input = split_but_quotes(input);
		i = 0;
		while(splited_input[i] != (char *)'\0')
		{
			printf("%s\n", splited_input[i]);
			++i;
		}
		i = 0;
		while (splited_input[i] != (char *)'\0')
		{
			free(splited_input[i]);
			++i;
		}
		free(splited_input);
	}
}
