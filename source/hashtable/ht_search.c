/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:10:38 by fbafica           #+#    #+#             */
/*   Updated: 2021/10/25 17:45:30 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*search_a_key(t_table *table, char *key)
{
	t_pair	*pair;
	t_pair	*tmp;
	int		index;

	index = hash_a_key(key, table->size);
	pair = table->pairs[index];
	if (pair)
	{
		if (!ft_strcmp(pair->key, key))
			return (pair->value);
		else
		{
			tmp = pair;
			while (tmp && ft_strcmp(tmp->key, key))
				tmp = tmp->next;
			if (tmp)
				return (tmp->value);
		}
	}
	return (NULL);
}
