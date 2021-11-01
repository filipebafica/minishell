/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:54:19 by fbafica           #+#    #+#             */
/*   Updated: 2021/10/29 16:55:31 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(char **commands)
{
	if (!ft_strcmp(*commands, "echo"))
		return (1);
	if (!ft_strcmp(*commands, "cd"))
		return (1);
	if (!ft_strcmp(*commands, "pwd"))
		return (1);
	if (!ft_strcmp(*commands, "export"))
		return (1);
	if (!ft_strcmp(*commands, "unset"))
		return (1);
	if (!ft_strcmp(*commands, "env"))
		return (1);
	if (!ft_strcmp(*commands, "exit"))
		return (1);
	return (0);
}
