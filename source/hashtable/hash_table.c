/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:52:29 by fbafica           #+#    #+#             */
/*   Updated: 2021/10/15 19:59:03 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_node(t_node *node)
{
	free(node->key);
	free(node->value);
	free(node);
}

void	free_table(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->size)
	{
		if (table->data[i] != NULL)
			free_history_entry(table->data[i]);
	}
	free(table->data);
	free(table);
}

t_node	*create_node(char *key, char *value, \
int key_size, int value_size)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->key = malloc(key_size);
	node->value = malloc(value_size);
	ft_strlcpy(node->key, key, key_size);
	ft_strlcpy(node->key, value, value_size);
	return (node);
}

t_table	*create_table(int size)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	table->size = size;
	table->count = 0;
	table->data = ft_calloc(size, sizeof(t_node *));
	return (table);
}
