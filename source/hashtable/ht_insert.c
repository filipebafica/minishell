/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 20:48:06 by fbafica           #+#    #+#             */
/*   Updated: 2021/12/06 22:42:50 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	non_empty_index(t_table *table, t_pair *curr, \
t_pair *new, int index)
{
	if (!ft_strcmp(curr->key, new->key))
	{
		table->pairs[index] = new;
		new->next = curr->next;
		free_pair(curr);
	}
	else
	{
		table->pairs[index] = new;
		new->next = curr;
		table->separate_chain++;
	}
}

static void	empty_index(t_table *table, t_pair *new, int index)
{
	if (table->count == table->size)
	{
		ft_putendl_fd("insert error: the table is full", 1);
		free_pair(new);
		return ;
	}
	table->pairs[index] = new;
	table->count++;
}

void	table_insert_pair(t_table *table, char *key, char *value)
{
	t_pair	*curr;
	t_pair	*new;
	int		index;

	index = hash_a_key(key, table->size);
	curr = table->pairs[index];
	new = create_pair(key, value);
	if (!curr)
		empty_index(table, new, index);
	else
		non_empty_index(table, curr, new, index);
}
