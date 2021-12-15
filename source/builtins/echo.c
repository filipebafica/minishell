/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:36:05 by fbafica           #+#    #+#             */
/*   Updated: 2021/12/15 18:17:48 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_arg(char *arg)
{
	int	arg_len;
	int	i;

	i = 0;
	arg_len = ft_strlen(arg);
	while (i < arg_len)
	{
		if (i < arg_len)
		{
			ft_putchar_fd(arg[i], 1);
		}
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
		while (!ft_strcmp(commands[i], "-n"))
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
