/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:49:23 by fbafica           #+#    #+#             */
/*   Updated: 2021/10/13 20:11:23 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/types.h>
#include <unistd.h>

int	main(void)
{
	char	*input_command;

	while (1)
	{
		input_command = readline("$");
		input_handler(&input_command);
		printf("%s\n", input_command);
	}
	return (0);
}
