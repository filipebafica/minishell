/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_sorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 23:54:38 by fbafica           #+#    #+#             */
/*   Updated: 2021/12/14 23:58:17 by fbafica          ###   ########.fr       */
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

int	export_sorted_vars(void)
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
