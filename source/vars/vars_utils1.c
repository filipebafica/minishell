/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:18:35 by fbafica           #+#    #+#             */
/*   Updated: 2021/11/26 21:00:44 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*join_key_value(int index)
{
	char	*key;
	char	*value;
	char	*tmp;
	char	*pair;

	tmp = ft_strdup(g_var_tables.env_var->pairs[index]->key);
	key = ft_strjoin(tmp, "=");
	value = ft_strdup(g_var_tables.env_var->pairs[index]->value);
	pair = ft_strjoin(key, value);
	free(tmp);
	free(key);
	free(value);
	return (pair);
}

char	**env_var_table_to_env_var_arr(void)
{
	char	**env_vars;
	char	*pair;
	int		i;
	int		j;

	env_vars = malloc((g_var_tables.env_var->count + 1) * sizeof(char *));
	i = 0;
	j = 0;
	while (i < g_var_tables.env_var->size)
	{
		if (g_var_tables.env_var->pairs[i])
		{
			pair = join_key_value(i);
			env_vars[j] = ft_strdup(pair);
			free(pair);
			++j;
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
		table_insert_pair(g_var_tables.env_var, key, value);
		free(key);
		++i;
	}
}

void	create_var_tables(void)
{
	g_var_tables.loc_var = create_table(100);
	g_var_tables.env_var = create_table(get_tokens_len(__environ) * 3);
}
