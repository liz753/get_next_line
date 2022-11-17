/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:45:49 by lfrank            #+#    #+#             */
/*   Updated: 2022/11/17 17:16:25 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_read_and_stash(t_var *var, int fd)
{
	char	*buf;

	// var->nbrc = 0;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 2));
	var->nbrc = read(fd, buf, BUFFER_SIZE);
	buf[var->nbrc] = '\0';
	if (buf == NULL)
	{
		var->tmp_stash = ft_strdup(buf);
		printf("%s", var->tmp_stash);
	}
	else
	{
		var->tmp_stash = ft_strjoin(var->tmp_stash, buf);
		printf("%s", var->tmp_stash);
	}
	free(buf);
	return (var->nbrc);
}

char	*get_next_line(int fd)
{
	t_var		var;
	static char	*stash;
	char		*old_stash;
	char		*line;
	int			line_len;

	var.tmp_stash = NULL;
	var.nbrc = 0;
	stash = var.tmp_stash;
	while (1)
	{
		if (ft_strchr(stash, '\n'))
		{
			line_len = ft_strlen_n(stash) + 2;
			line = ft_substr(stash, 0, line_len);
			old_stash = stash;
			stash = ft_substr(stash, line_len, 0);
			free(old_stash);
			return (line);
		}
		else
		{
			var.nbrc = ft_read_and_stash(&var, fd);
			if (var.nbrc == 0)
				break ;
		}
	}
	return (stash);
}
