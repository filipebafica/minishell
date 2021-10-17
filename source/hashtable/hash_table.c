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

void	free_pair(t_pair *pair)
{
	free(pair->key);
	free(pair->value);
	free(pair);
}

void	free_table(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->size)
	{
		if (table->pairs[i] != NULL)
			free_pair(table->pairs[i]);
		++i;
	}
	free(table->pairs);
	free(table);
}

t_pair	*create_pair(char *key, char *value)
{
	t_pair	*pair;

	pair = ft_calloc(1, sizeof(t_pair));
	pair->key = ft_strdup(key);
	pair->value = ft_strdup(value);
	return (pair);
}

t_table	*create_table(int size)
{
	t_table	*table;

	table = ft_calloc(1, sizeof(t_table));
	table->size = size;
	table->count = 0;
	table->pairs = ft_calloc(size, sizeof(t_pair));
	return (table);
}
