/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 23:18:48 by fbafica           #+#    #+#             */
/*   Updated: 2021/10/21 23:26:05 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	tokens_len(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i] != (char *)'\0')
		++i;
	return (i);
}