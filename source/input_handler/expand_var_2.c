/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:45:04 by fbafica           #+#    #+#             */
/*   Updated: 2021/12/10 19:45:02 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_var_len(char *token, int start)
{
	int	len;
	int	i;

	len = ft_strlen(token);
	if (len > 1 && (token[len - 1] == "'"[0] || token[len - 1] == '"'))
		--len;
	i = 0;
	while (start + i < len)
	{
		if (token[start + i] == ' ' || token[start + i] == "'"[0] \
		|| token[start + i] == '"')
			break ;
		++i;
	}
	return (i);
}

void	replace_var(char **token, int var_start)
{
	int		var_len;
	char	*tmp_1;
	char	*tmp_2;
	char	*tmp_3;
	char	*key;

	var_len = get_var_len(*token, var_start + 1);
	tmp_1 = ft_substr(*token, 0, var_start);
	key = ft_substr(*token, var_start + 1, var_len);
	tmp_2 = ft_strjoin(tmp_1, get_value_by_key(key));
	tmp_3 = ft_strdup(*token + var_start + 1 + var_len);
	free(*token);
	*token = ft_strjoin(tmp_2, tmp_3);
	if (key)
		free(key);
	if (tmp_1)
		free(tmp_1);
	if (tmp_2)
		free(tmp_2);
	if (tmp_3)
		free(tmp_3);
}

static int	check_sing(char *token, int var_start)
{
	int	i;
	int	j;
	int	sing;
	int	open_by_doub;

	j = 0;
	open_by_doub = 1;
	sing = 0;
	i = 0;
	while (token[i] && i < var_start)
	{
		if (token[i] == "'"[0])
			++sing;
		if (sing == 2)
		{
			sing = 0;
			j = i + 1;
		}
		++i;
	}
	if (ft_strchrlen(token + j, '"') >= ft_strchrlen(token + j, "'"[0]))
		open_by_doub = 0;
	if (sing % 2 == 0 || open_by_doub)
		return (1);
	return (0);
}

static int	check_doub(char *token, int var_start)
{
	int	i;
	int	j;
	int	doub;
	int	open_by_doub;

	j = 0;
	open_by_doub = 1;
	doub = 0;
	i = 0;
	while (token[i] && i < var_start)
	{
		if (token[i] == '"')
			++doub;
		if (doub == 2)
		{
			doub = 0;
			j = i + 1;
		}
		++i;
	}
	if (ft_strchrlen(token + j, '"') > ft_strchrlen(token + j, "'"[0]))
		open_by_doub = 0;
	if (!ft_strchr(token, '"') || doub % 2 != 0 || (open_by_doub && doub))
		return (1);
	return (0);
}

int	check_expand_var(char *token, int var_start)
{
	int	sing;
	int	doub;

	sing = check_sing(token, var_start);
	doub = check_doub(token, var_start);
	if (ft_strcmp(token, "") && sing && doub && \
	token[var_start] != ' ' && token[var_start] != '\0')
		return (1);
	return (0);
}
