/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:48:25 by fbafica           #+#    #+#             */
/*   Updated: 2021/12/02 17:10:53 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	sort_env(char **env_arr)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	while (env_arr[i])
	{
		j = 0;
		while (env_arr[j])
		{
			if (ft_strcmp(env_arr[i], env_arr[j]) < 0)
			{
				tmp = env_arr[i];
				env_arr[i] = env_arr[j];
				env_arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	export_sorted_vars(void)
{
	char	**env_arr;
	char	*key;
	int		equal_sign;
	int		i;

	env_arr = env_var_table_to_env_var_arr();
	sort_env(env_arr);
	i = 0;
	while (env_arr[i])
	{
		equal_sign = ft_strchrlen(env_arr[i], '=');
		key = ft_substr(env_arr[i], 0, equal_sign);
		ft_printf("declare -x %s=\"%s\"\n", key, env_arr[i] + equal_sign + 1);
		free(key);
		++i;
	}
	free_tokens(env_arr);
	return (1);
}

static void	handle_env_var(char *var_key, char *var_value)
{
	table_insert_pair(g_minishell.env_var, var_key, var_value);
	if (search_a_key(g_minishell.loc_var, var_key))
		table_delete_pair(g_minishell.loc_var, var_key);
}

static int	export_var(char **commands)
{
	char	*key;
	int		equal_sign;
	int		i;

	i = 0;
	while (commands[i])
	{
		equal_sign = ft_strchrlen(commands[i], '=');
		if (equal_sign)
		{
			key = ft_substr(commands[i], 0, equal_sign);
			handle_env_var(key, commands[i] + equal_sign + 1);
			free(key);
		}
		++i;
	}
	return (1);
}

int	export_func(char **commands)
{
	int	status;

	if (!ft_strcmp(commands[1], ""))
		status = export_sorted_vars();
	else
		status = export_var(commands);
	table_insert_pair(g_minishell.loc_var, "?", "0");
	return (status);
}
