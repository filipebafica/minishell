/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:18:35 by fbafica           #+#    #+#             */
/*   Updated: 2021/12/07 13:38:15 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*join_key_value(char *key, char *value)
{
	char	*tmp;
	char	*pair;

	tmp = ft_strjoin(key, "=");
	pair = ft_strjoin(tmp, value);
	free(tmp);
	return (pair);
}

char	**env_var_table_to_env_var_arr(void)
{
	t_pair	*tmp;
	char	**env_vars;
	int		i;
	int		j;

	env_vars = malloc((g_minishell.env_var->count + \
	g_minishell.env_var->separate_chain + 1) * sizeof(char *));
	i = 0;
	j = 0;
	while (i < g_minishell.env_var->size)
	{
		if (g_minishell.env_var->pairs[i])
		{
			tmp = g_minishell.env_var->pairs[i];
			while (tmp)
			{
				env_vars[j] = join_key_value(tmp->key, tmp->value);
				++j;
				tmp = tmp->next;
			}
		}
		++i;
	}
	env_vars[j] = (char *) '\0';
	return (env_vars);
}

void	env_var_arr_to_env_var_table(char **env_var)
{
	char	*key;
	char	*value;
	int		i;

	i = 0;
	while (env_var[i])
	{
		key = ft_substr(env_var[i], 0, ft_strchrlen(env_var[i], '='));
		value = ft_strchr(env_var[i], '=') + 1;
		table_insert_pair(g_minishell.env_var, key, value);
		free(key);
		++i;
	}
}

void	create_var_tables(void)
{
	g_minishell.loc_var = create_table(100);
	g_minishell.env_var = create_table(get_tokens_len(__environ) * 3);
	g_minishell.error_status = create_table(1);
}
