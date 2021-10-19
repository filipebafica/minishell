/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:49:23 by fbafica           #+#    #+#             */
/*   Updated: 2021/10/18 22:11:04 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/types.h>
#include <unistd.h>

int	main(void)
{
	// char	*input_command;
	t_table	*hash_table;

	// while (1)
	// {
	// 	input_command = readline("$");
	// 	input_handler(&input_command);
	// 	printf("%s\n", input_command);
	// }
	hash_table = create_table(10);
	table_insert_pair(hash_table, "1", "First address");
	table_insert_pair(hash_table, "2", "Second address");
	table_insert_pair(hash_table, "Hel", "Third address");
	table_insert_pair(hash_table, "Cau", "Fourth address");
	table_insert_pair(hash_table, "Gfl", "Fith address");
	print_search(hash_table, "1");
	print_search(hash_table, "2");
	print_search(hash_table, "3");
	print_search(hash_table, "Hel");
	print_search(hash_table, "Cau");
	table_delete_pair(hash_table, "Hel");
	print_search(hash_table, "Hel");
	print_table(hash_table);
	free_table(hash_table);
	return (0);
}
