/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 19:12:38 by mboy              #+#    #+#             */
/*   Updated: 2021/09/08 19:15:05 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

char	*gnl_line(char *line, int size, int letter)
{
	int		idx;
	char	*tmp;

	idx = -1;
	tmp = malloc(sizeof(char) * (size + 1));
	if (!tmp)
		return (NULL);
	if (line != NULL)
		while (line[++idx])
			tmp[idx] = line[idx];
	else
		idx++;
	tmp[idx] = letter;
	tmp[idx + 1] = '\0';
	free (line);
	line = NULL;
	return (tmp);
}

int	gnl(int fd, char **line)
{
	int			ret;
	static char	letter;
	static int	size;

	size = 1;
	letter = 0;
	if (fd < 0 || fd > 255 || line == NULL)
		return (-1);
	if (*line)
	{
		free(*line);
		*line = NULL;
	}
	ret = read(fd, &letter, 1);
	while (ret > 0)
	{
		if (letter == '\n')
			return (ret & (size = 1));
		*line = gnl_line(*line, size++, letter);
		ret = read(fd, &letter, 1);
	}
	return (ret);
}
