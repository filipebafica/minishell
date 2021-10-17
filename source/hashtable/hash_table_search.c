/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table_search.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:10:38 by fbafica           #+#    #+#             */
/*   Updated: 2021/10/17 13:44:52 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*search_a_key(t_table *table, char *key)
{
	t_pair	*pair;
	int		index;

	index = hash_a_key(key, table->size);
	pair = table->pairs[index];
	if (pair)
	{
		if (ft_strncmp(pair->key, key, ft_strlen(key)) == 0)
			return (pair->value);
	}
	return (NULL);
}

void	print_search(t_table *table, char *key)
{
	char	*value;

	value = search_a_key(table, key);
	if (!value)
	{
		printf("key: %s doesn't exist\n", key);
		return ;
	}
	else
		printf("key: %s, value: %s\n", key, value);
}

void	print_table(t_table *table)
{
	int	i;

	printf("\nHash Table\n-------------------\n");
	i = 0;
	while (i < table->size)
	{
		if (table->pairs[i])
		{
			printf("Index: %d, Key: %s, Value: %s\n", i, table->pairs[i]->key, \
			table->pairs[i]->value);
		}
		++i;
	}
	printf("-------------------\n\n");
}
