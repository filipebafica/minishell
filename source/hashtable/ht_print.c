/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 22:07:59 by fbafica           #+#    #+#             */
/*   Updated: 2021/10/18 22:09:05 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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