/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 22:07:59 by fbafica           #+#    #+#             */
/*   Updated: 2021/12/04 18:10:26 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_search(t_table *table, char *key)
{
	char	*value;

	value = search_a_key(table, key);
	if (!value)
		return ;
	else
		ft_printf("%s", value);
}

void	print_table(t_table *table)
{
	t_pair	*tmp;
	int		i;

	i = 0;
	while (i < table->size)
	{
		if (table->pairs[i])
		{
			tmp = table->pairs[i];
			while (tmp)
			{
				ft_printf("%s=%s\n", tmp->key, tmp->value);
				tmp = tmp->next;
			}
		}
		++i;
	}
}
