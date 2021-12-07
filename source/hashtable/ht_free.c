/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:55:57 by fbafica           #+#    #+#             */
/*   Updated: 2021/12/06 22:17:16 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_pair(t_pair *pair)
{
	free(pair->key);
	free(pair->value);
	free(pair);
}

void	free_linked_pair(t_pair *pair)
{
	t_pair	*tmp_curr;
	t_pair	*tmp_next;

	tmp_curr = pair;
	while (tmp_next != NULL)
	{
		tmp_next = tmp_curr->next;
		free_pair(tmp_curr);
		tmp_curr = tmp_next;
	}
}

void	free_table(t_table *table)
{
	int		i;

	i = 0;
	while (i < table->size)
	{
		if (table->pairs[i] != NULL && table->pairs[i]->next == NULL)
			free_pair(table->pairs[i]);
		else if (table->pairs[i] != NULL && table->pairs[i]->next != NULL)
			free_linked_pair(table->pairs[i]);
		++i;
	}
	free(table->pairs);
	free(table);
}
