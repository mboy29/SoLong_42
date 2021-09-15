/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 12:50:36 by mboy              #+#    #+#             */
/*   Updated: 2021/09/07 14:48:58 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

int	map_line(char *line)
{
	int	idx;

	idx = -1;
	while (line[++idx])
	{
		if (line[idx] != '1' && line[idx] != '0' && line[idx] != 'C'
			&& line[idx] != 'P' && line[idx] != 'E' && line[idx] != '\0')
			return (-1);
	}
	return (0);
}

void	map_xy(t_solong *data, int fd)
{
	int			idx;
	char		*line;

	line = NULL;
	idx = 1;
	while ((idx == gnl(fd, &line)) > 0)
	{
		if (!line || map_line(line) == -1)
			solong_exit(data, EXIT_FAILURE, "[ERROR]: Invalid map.\n");
		if (data->map_xy[0] == 0)
			data->map_xy[0] = ft_strlen(line);
		if (ft_strlen(line) != data->map_xy[0])
			solong_exit(data, EXIT_FAILURE, "[ERROR]: Invalid map.\n");
		data->map_xy[1] += 1;
		free (line);
		line = NULL;
	}
	if (!line || map_line(line) == -1)
		solong_exit(data, EXIT_FAILURE, "[ERROR]: Invalid map.\n");
	data->map_xy[1] += 1;
	free (line);
	line = NULL;
	return ((void)close (fd));
}

void	map_check(t_solong *data)
{
	int		idx[2];

	idx[0] = -1;
	while (++idx[0] != data->map_xy[0])
	{
		if (data->map[0][idx[0]] != '1'
			|| data->map[data->map_xy[1] - 1][idx[0]] != '1')
			solong_exit(data, EXIT_FAILURE, "[ERROR]: Invalid map.\n");
	}
	idx[1] = -1;
	while (++idx[1] != data->map_xy[1])
	{
		if (data->map[idx[1]][0] != '1'
			|| data->map[idx[1]][data->map_xy[0] - 1] != '1')
			solong_exit(data, EXIT_FAILURE, "[ERROR]: Invalid map.\n");
	}
	return ;
}

void	map(t_solong *data)
{
	if (data->mlx->img)
	{
		mlx_destroy_image(data->mlx->init, data->mlx->img);
		data->mlx->img = NULL;
		data->mlx->img_add = NULL;
		data->mlx->img_bpp = 0;
		data->mlx->img_end = 0;
		data->mlx->img_len = 0;
	}
	data->mlx->img = mlx_new_image(data->mlx->init,
			data->win_xy[0], data->win_xy[1]);
	if (!data->mlx->img)
		solong_exit(data, EXIT_FAILURE, "[ERROR]: mlx_new_image() failed.\n");
	data->mlx->img_add = mlx_get_data_addr(data->mlx->img,
			&data->mlx->img_bpp, &data->mlx->img_len, &data->mlx->img_end);
	draw_map(data);
}
