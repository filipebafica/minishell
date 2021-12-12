/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:10:38 by fbafica           #+#    #+#             */
/*   Updated: 2021/12/12 00:40:03 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	get_input_and_write( int tmp_file, char *eof_token)
{
	char	*input;
	int		tmp_fd[2];

	save_std_fd(tmp_fd);
	replace_std_fd(g_minishell.std_fd);
	here_doc_signals();
	while (1)
	{
		input = readline("> ");
		if (!input)
			kill_process();
		if (!ft_strcmp(input, eof_token))
		{
			free(input);
			break ;
		}
		else
			ft_putendl_fd(input, tmp_file);
		free(input);
	}
	replace_std_fd(tmp_fd);
	close(tmp_fd[IN]);
	close(tmp_fd[OUT]);
	exit(0);
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
	int		pid;
	int		status;
	char	*error_status;

	tmp_file = create_tmp_file();
	if (tmp_file < 0)
		return (0);
	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid == 0)
		get_input_and_write(tmp_file, eof_token);
	else
		waitpid(pid, &status, 0);
	if (WIFEXITED(status))
	{
		error_status = ft_itoa(WEXITSTATUS(status));
		table_insert_pair(g_minishell.error_status, "?", error_status);
		free(error_status);
	}
	tmp_file = open(TMP_FILE, O_RDONLY);
	dup2(tmp_file, STDIN_FILENO);
	close(tmp_file);
	return (1);
}
