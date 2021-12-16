/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:36:05 by fbafica           #+#    #+#             */
/*   Updated: 2021/12/15 22:20:16 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	not_print(void)
{
	return ;
}

static	int	who_opend(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '"')
			return (1);
		if (s[i] == "'"[0])
			return (2);
	}
	return (0);
}

static int	print_quote(char *s, int index)
{
	char	*tmp;
	int		print_quote;

	tmp = ft_substr(s, 0, index);
	if (!who_opend(tmp))
		print_quote = 0;
	else if (s[index] == "'"[0] && who_opend(tmp) == 1)
		print_quote = 1;
	else if (s[index] == '"' && who_opend(tmp) == 2)
		print_quote = 1;
	else
		print_quote = 0;
	free(tmp);
	return (print_quote);
}

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
			if ((arg[i] == '"' || arg[i] == "'"[0]) \
			&& !print_quote(arg, i))
				not_print();
			else
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
