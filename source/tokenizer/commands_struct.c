/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 21:00:20 by fbafica           #+#    #+#             */
/*   Updated: 2021/10/21 23:41:08 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_command	*add_command(char *command)
{
	t_command	*new_node;

	new_node = malloc(sizeof(t_command));
	new_node->command = ft_strdup(command);
	new_node->next = NULL;
	return (new_node);
}

void feed_commands(t_command **head, char **tokens, int num_tokens)
{
	t_command	*tmp;

	while (num_tokens >= 0)
	{
		tmp = add_command(tokens[num_tokens]);
		if (*head)
			tmp->next = *head;
		*head = tmp;
		--num_tokens;
	}
}
