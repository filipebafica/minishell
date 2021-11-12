/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:49:23 by fbafica           #+#    #+#             */
/*   Updated: 2021/11/12 18:15:46 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	int	status;

	create_var_tables();
	env_var_to_var_table(__environ);
	status = 1;
	while (status)
		status = run_shell();
	return (0);
}
