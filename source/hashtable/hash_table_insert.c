/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table_insert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 20:48:06 by fbafica           #+#    #+#             */
/*   Updated: 2021/10/17 13:12:26 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	non_empty_index(t_pair *curr, t_pair *new)
{
	if (ft_strncmp(curr->key, new->key, ft_strlen(new->key)) == 0)
	{
		ft_strlcpy(curr->value, new->value, ft_strlen(new->value) + 1);
		free_pair(new);
		return ;
	}
	else
	{
		printf("handle_colision(table, new);\n");
		return ;
	}
}

static void	empty_index(t_table *table, t_pair *new, int index)
{
	if (table->count == table->size)
	{
		printf("insert error: the table is full\n");
		free_pair(new);
		return ;
	}
	table->pairs[index] = new;
	table->count++;
}

void	table_insert(t_table *table, char *key, char *value)
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
		non_empty_index(curr, new);
}
