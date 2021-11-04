/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:41:48 by fbafica           #+#    #+#             */
/*   Updated: 2021/11/04 00:49:36 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	char	*buffer;

	buffer = malloc(99);
	read(STDIN_FILENO, buffer, 99);
	printf("reading: %s", buffer);
	if (buffer)
		free(buffer);
	return (0);
}
