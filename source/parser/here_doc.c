/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:10:38 by fbafica           #+#    #+#             */
/*   Updated: 2021/12/04 17:24:22 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	update_buffer(char **buffer, char *input)
{
	char	*tmp;
	char	*tmp_2;

	tmp = ft_strdup(*buffer);
	tmp_2 = ft_strjoin(input, "\n");
	free(*buffer);
	*buffer = ft_strjoin(tmp, tmp_2);
	free(tmp);
	free(tmp_2);
}

static char	*get_user_input(char *eof_token)
{
	char	*buffer;
	char	*input;
	int		tmp_fd[2];

	save_std_fd(tmp_fd);
	replace_std_fd(g_minishell.std_fd);
	buffer = ft_calloc(1, 1);
	while (1)
	{
		input = readline(">");
		if (!input)
		{
			write(1, "\n", 1);
			exit(0);
		}
		if (!ft_strcmp(input, eof_token))
		{
			free(input);
			break ;
		}
		update_buffer(&buffer, input);
		free(input);
	}
	replace_std_fd(tmp_fd);
	return (buffer);
}

static void	write_on_file(int tmp_file, char *eof_token)
{
	char	*buffer;

	buffer = get_user_input(eof_token);
	write(tmp_file, buffer, ft_strlen(buffer));
	close(tmp_file);
	free(buffer);
}

static int	create_tmp_file(void)
{
	int	file;

	file = open(TMP_FILE, O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (file < 0)
	{
		perror("error");
		return (0);
	}
	return (file);
}

int	here_doc(char *eof_token)
{
	int		tmp_file;

	tmp_file = create_tmp_file();
	if (tmp_file < 0)
		return (0);
	write_on_file(tmp_file, eof_token);
	tmp_file = open(TMP_FILE, O_RDONLY);
	dup2(tmp_file, STDIN_FILENO);
	close(tmp_file);
	return (1);
}
