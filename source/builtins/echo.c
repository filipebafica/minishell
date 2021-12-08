/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:36:05 by fbafica           #+#    #+#             */
/*   Updated: 2021/12/07 19:57:20 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_var_len(char *arg, int start, int max_len)
{
	int	i;

	i = 0;
	while (start + i < max_len)
	{
		if (arg[start + i] == ' ' || arg[start + i] == "'"[0] \
		|| arg[start + i] == '"')
			break ;
		++i;
	}
	return (i);
}

static int	print_var(char *arg, int start, int arg_len)
{
	int		var_len;
	char	*key;

	++start;
	var_len = get_var_len(arg, start, arg_len);
	key = ft_substr(arg, start, var_len);
	print_search(g_minishell.env_var, key);
	print_search(g_minishell.loc_var, key);
	print_search(g_minishell.error_status, key);
	free(key);
	return (var_len);
}

static int	check_expand_var(char *arg)
{
	int	start_with_single;

	if (arg[0] == "'"[0])
		start_with_single = 1;
	else
		start_with_single = 0;
	while (*arg)
	{
		if (*arg == '$' && !start_with_single && *(arg + 1) != ' ' \
		&& *(arg + 1) != '\0')
			return (1);
		++arg;
	}
	return (0);
}

static void	print_arg(char *arg)
{
	int	expand_var;
	int	arg_len;
	int	i;

	i = 0;
	if (arg[0] == "'"[0] || arg[0] == '"')
		++i;
	arg_len = ft_strlen(arg);
	if (arg_len > 1 && (arg[arg_len - 1] == "'"[0] || arg[arg_len - 1] == '"'))
		--arg_len;
	expand_var = check_expand_var(arg);
	while (i < arg_len)
	{
		if (arg[i] == '$' && expand_var)
			i += (1 + print_var(arg, i, arg_len));
		if (i < arg_len)
			ft_putchar_fd(arg[i], 1);
		++i;
	}
}

int	echo(char **commands)
{
	int	commands_len;
	int	i;

	commands_len = get_tokens_len(commands);
	i = 1;
	if (!ft_strcmp(commands[i], "-n"))
		++i;
	while (commands[i])
	{
		print_arg(commands[i]);
		if (i < (commands_len - 1))
			ft_printf(" ");
		++i;
	}
	if (ft_strcmp(commands[1], "-n"))
		ft_printf("\n");
	table_insert_pair(g_minishell.error_status, "?", "0");
	return (1);
}
