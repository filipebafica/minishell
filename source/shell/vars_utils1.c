/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:18:35 by fbafica           #+#    #+#             */
/*   Updated: 2021/11/23 21:06:22 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_var_tables(void)
{
	g_var_tables.loc_var = create_table(100);
	g_var_tables.env_var = create_table(get_tokens_len(__environ) * 3);
}
