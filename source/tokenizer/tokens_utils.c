/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:20:35 by fbafica           #+#    #+#             */
/*   Updated: 2021/10/24 14:31:21 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i] != (char *) '\0')
	{
		printf("%s\n", (tokens[i]));
		++i;
	}
}

void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i] != (char *) '\0')
	{
		free(tokens[i]);
		++i;
	}
	free(tokens);
}
