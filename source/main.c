/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:49:23 by fbafica           #+#    #+#             */
/*   Updated: 2021/12/06 20:45:55 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	int	status;

	create_var_tables();
	env_var_arr_to_env_var_table(__environ);
	table_insert_pair(g_minishell.error_status, "?", "0");
	save_std_fd(g_minishell.std_fd);
	status = 1;
	while (status)
		status = run_shell();
	return (0);
}
