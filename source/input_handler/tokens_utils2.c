/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:22:26 by fbafica           #+#    #+#             */
/*   Updated: 2021/11/26 22:09:07 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	delete_a_token(char ***tokens, int index)
{
	char	**tmp_1;
	char	**tmp_2;
	int		len;

	len = get_tokens_len(*tokens);
	if (index >= len)
		return ;
	tmp_1 = sub_tokens(*tokens, 0, index);
	tmp_2 = sub_tokens(*tokens, (index + 1), len - (index + 1));
	free_tokens(*tokens);
	*tokens = join_tokens(tmp_1, tmp_2);
	free_tokens(tmp_1);
	free_tokens(tmp_2);
}
