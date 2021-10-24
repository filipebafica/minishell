/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:46:30 by fbafica           #+#    #+#             */
/*   Updated: 2021/10/24 19:09:23 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**input_handler(char *input)
{
	char	**tokens;

	if (quotes_check(input) == 0)
	{
		printf("bad syntax\n");
		tokens = NULL;
	}
	else
	{
		space_handler(&input);
		add_history(input);
		tokens = get_tokens(input);
	}
	return (tokens);
}
