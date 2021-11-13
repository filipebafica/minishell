/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:18:35 by fbafica           #+#    #+#             */
/*   Updated: 2021/11/12 19:48:55 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static void	handle_local_var(char *var_key, char *var_value)
// {
// 	table_insert_pair(g_var_tables.env_var, var_key, var_value);
// }

// void	expand_var(char **tokens)
// {
// 	int	i;

// 	i = 0;
// 	while (tokens[i])
// 	{
// 		if (!ft_strcmp(tokens[i], "="))
// 		{
// 			if (i - 2 >= 0 && (!ft_strcmp(tokens[i - 2], "export") 
// 			|| !ft_strcmp(tokens[i - 2], "unset")))
// 				handle_env_var(tokens[i - 2], tokens[i - 1], tokens[i + 1]);
// 			else
// 				handle_local_var(tokens[i - 1], tokens[i + 1]);
// 		}
// 		++i;
// 	}
// }

void	create_var_tables(void)
{
	g_var_tables.loc_var = create_table(100);
	g_var_tables.env_var = create_table(get_tokens_len(__environ) * 3);
}
