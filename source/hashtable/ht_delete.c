/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_delete.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 17:22:23 by fbafica           #+#    #+#             */
/*   Updated: 2021/10/25 17:44:15 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	delete_in_a_linked_pair(t_table *table, t_pair *curr, char *key)
{
	t_pair	*prev_tmp;
	t_pair	*curr_tmp;
	int		index;

	prev_tmp = NULL;
	curr_tmp = curr;
	while (curr_tmp && ft_strcmp(curr_tmp->key, key))
	{
		prev_tmp = curr_tmp;
		curr_tmp = curr_tmp->next;
	}
	if (curr_tmp && prev_tmp)
	{
		prev_tmp->next = curr_tmp->next;
		free_pair(curr_tmp);
	}
	else
	{
		index = hash_a_key(key, table->size);
		table->pairs[index] = curr->next;
		free_pair(curr);
	}
}

void	table_delete_pair(t_table *table, char *key)
{
	t_pair	*curr;
	int		index;

	index = hash_a_key(key, table->size);
	curr = table->pairs[index];
	if (!curr)
		return ;
	if (curr->next == NULL)
	{
		free_pair(curr);
		table->pairs[index] = NULL;
	}
	else if (curr->next != NULL)
		delete_in_a_linked_pair(table, curr, key);
}
