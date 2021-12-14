/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:08:49 by fbafica           #+#    #+#             */
/*   Updated: 2021/12/13 18:57:32 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec(char **commands, char **tokens)
{
	if (!*commands)
		return (1);
	else if (is_builtin(commands, check_a_token(tokens, "|")))
		return (exec_builtin(commands));
	else
		return (exec_non_builtin(commands));
}
