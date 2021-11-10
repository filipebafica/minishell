/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:36:05 by fbafica           #+#    #+#             */
/*   Updated: 2021/11/10 18:55:11 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_var(char *arg, int start, int len)
{
	print_search(g_var_tables.env_var, ft_substr(arg, start, len));
	print_search(g_var_tables.loc_var, ft_substr(arg, start, len));
}

static int	get_var_len(char *arg, int start, int max_len)
{
	int	i;

	i = 0;
	while (start + i < max_len)
	{
		if (arg[start + i] == ' ' || arg[start + i] == "'"[0] || arg[start + i] == '"')
			break ;
		++i;
	}
	return (i);
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
	int	var_end;
	int	len;
	int	i;

	i = 0;
	if (arg[0] == "'"[0] || arg[0] == '"')
		++i;
	len = ft_strlen(arg);
	if (arg[len - 1] == "'"[0] || arg[len - 1] == '"')
		--len;
	expand_var = check_expand_var(arg);
	while (i < len)
	{
		if (arg[i] == '$' && expand_var)
		{
			++i;
			var_end = get_var_len(arg, i, len);
			print_var(arg, i, var_end);
			i += var_end;
		}
		if (i < len)
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
	if (!ft_strcmp(commands[1], "-n"))
		++i;
	while (commands[i])
	{
		print_arg(commands[i]);
		if (i < (commands_len - 1))
			ft_putchar_fd(' ', 1);
		++i;
	}
	if (ft_strcmp(commands[1], "-n"))
		ft_putchar_fd('\n', 1);
	return (1);
}
