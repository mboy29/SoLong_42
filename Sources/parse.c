/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 12:31:02 by mboy              #+#    #+#             */
/*   Updated: 2021/09/08 18:46:24 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

void	parse_data_doublon(t_solong *data, int idx0, int idx1)
{
	static int		doublon[2] = {0, 0};

	if (data->map[idx0][idx1] == 'P')
	{
		if (doublon[0] == 1)
			solong_exit(data, EXIT_FAILURE,
				"[ERROR]: Invalid map.\n");
		data->player_xy[0] = idx1;
		data->player_xy[1] = idx0;
		if (doublon[0] == 0)
			doublon[0] = 1;
	}
	if (data->map[idx0][idx1] == 'E')
	{
		if (doublon[1] == 1)
			solong_exit(data, EXIT_FAILURE,
				"[ERROR]: Invalid map.\n");
		data->exit_xy[0] = idx1;
		data->exit_xy[1] = idx0;
		if (doublon[1] == 0)
			doublon[1] = 1;
	}
	return ;
}

void	parse_data(t_solong *data)
{
	int		idx[2];

	idx[0] = -1;
	while (++idx[0] < data->map_xy[1])
	{
		idx[1] = -1;
		while (++idx[1] < data->map_xy[0])
		{
			if (data->map[idx[0]][idx[1]] == 'C')
				data->collect += 1;
			parse_data_doublon(data, idx[0], idx[1]);
		}
	}
	return ;
}

void	parse_data_collect(t_solong *data)
{
	int		idx[3];

	idx[2] = 0;
	idx[1] = -1;
	while (data->map[++idx[1]])
	{
		idx[0] = -1;
		while (data->map[idx[1]][++idx[0]])
		{
			if (data->map[idx[1]][idx[0]] == 'C')
			{
				data->collect_xy[idx[2]] = malloc(sizeof(int) * 2);
				if (!data->collect_xy[idx[2]])
					solong_exit(data, EXIT_FAILURE,
						"[ERROR]: malloc() failed.\n");
				data->collect_xy[idx[2]][0] = idx[0];
				data->collect_xy[idx[2]][1] = idx[1];
				idx[2]++;
			}
		}
	}
	data->collect_xy[idx[2]] = NULL;
	return ;
}

void	parse_map(t_solong *data, char *mapath)
{
	int		idx[3];
	char	*line;

	idx[2] = open(mapath, O_RDONLY);
	if (idx[2] <= 0 || idx[2] > 255)
		solong_exit(data, EXIT_FAILURE, "[ERROR]: Invalid path to map.\n");
	line = NULL;
	idx[1] = 0;
	idx[0] = 1;
	while ((idx[0] == gnl(idx[2], &line)) > 0)
	{
		data->map[idx[1]] = ft_strdup(line);
		if (!data->map[idx[1]++])
			solong_exit(data, EXIT_FAILURE, "[ERROR]: malloc() failed.\n");
		free(line);
		line = NULL;
	}
	data->map[idx[1]] = ft_strdup(line);
	if (!data->map[idx[1]])
		solong_exit(data, EXIT_FAILURE, "[ERROR]: malloc() failed.\n");
	data->map[idx[1] + 1] = NULL;
	free(line);
	line = NULL;
	close (idx[2]);
	return ((void)map_check(data));
}

void	parse(t_solong *data, char *mapath)
{
	int		fd[2];

	fd[0] = open(mapath, O_DIRECTORY);
	fd[1] = open(mapath, O_RDONLY);
	if (fd[1] <= 0 || fd[1] > 255 || fd[0] != -1)
		solong_exit(data, EXIT_FAILURE, "[ERROR]: Invalid path to map.\n");
	map_xy(data, fd[1]);
	data->map = malloc(sizeof(char *) * (data->map_xy[1] + 1));
	if (!data->map)
		solong_exit(data, EXIT_FAILURE, "[ERROR]: malloc() failed.\n");
	parse_map(data, mapath);
	parse_data(data);
	if ((data->player_xy[0] == 0 && data->player_xy[1] == 0)
		|| (data->exit_xy[0] == 0 && data->exit_xy[1] == 0)
		|| data->collect == 0)
		solong_exit(data, EXIT_FAILURE,
			"[ERROR]: Invalid map.\n");
	data->collect_xy = malloc(sizeof(int *) * (data->collect + 1));
	if (!data->collect_xy)
		solong_exit(data, EXIT_FAILURE, "[ERROR]: malloc() failed.\n");
	parse_data_collect(data);
	return ;
}
