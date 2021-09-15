/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:11:20 by mboy              #+#    #+#             */
/*   Updated: 2021/09/08 18:51:38 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

int	collect_idx(t_solong *data)
{
	int			idx;
	static int	collect = 0;

	idx = -1;
	if (collect == 0)
		collect = data->collect;
	while (data->collect_xy[++idx])
	{
		if ((int)data->player_xy[0] == data->collect_xy[idx][0]
			&& (int)data->player_xy[1] == data->collect_xy[idx][1])
		{
			data->collect -= 1;
			data->collected += 1;
			ft_putstr("[GAME]: ");
			ft_putnbr(data->collected);
			if (data->collected == 1)
				ft_putstr(" collectable out of ");
			else
				ft_putstr(" collectables out of ");
			ft_putnbr(collect);
			ft_putstr(".\n");
			return (idx);
		}
	}
	return (-1);
}

char	**collect_update_map_bis(t_solong *data, char **new_map)
{
	int		idx[2];

	idx[0] = -1;
	while (++idx[0] != data->map_xy[1])
	{
		new_map[idx[0]] = malloc(sizeof(char) * (data->map_xy[0] + 1));
		if (!new_map[idx[0]])
			solong_exit(data, EXIT_FAILURE, "[ERROR]: malloc() failed.\n");
		idx[1] = -1;
		while (data->map[idx[0]][++idx[1]])
		{
			if (idx[0] == (int)data->player_xy[1]
				&& idx[1] == (int)data->player_xy[0])
				new_map[idx[0]][idx[1]] = '0';
			else
				new_map[idx[0]][idx[1]] = data->map[idx[0]][idx[1]];
		}
		new_map[idx[0]][idx[1]] = '\0';
		free (data->map[idx[0]]);
		data->map[idx[0]] = NULL;
	}
	new_map[idx[0]] = NULL;
	return (new_map);
}

char	**collect_update_map(t_solong *data)
{
	char	**new_map;

	new_map = malloc(sizeof(char *) * (data->map_xy[1] + 1));
	if (!new_map)
		solong_exit(data, EXIT_FAILURE, "[ERROR]: malloc() failed.\n");
	new_map = collect_update_map_bis(data, new_map);
	free (data->map);
	data->map = NULL;
	return (new_map);
}

int	**collect_update(t_solong *data, int collected)
{
	int		idx[2];
	int		**new_collect;

	new_collect = malloc(sizeof(int *) * (data->collect + 1));
	if (!new_collect)
		solong_exit(data, EXIT_FAILURE, "[ERROR]: malloc() failed.\n");
	idx[0] = -1;
	idx[1] = 0;
	while (data->collect_xy[++idx[0]])
	{
		if (idx[0] != collected)
		{
			new_collect[idx[1]] = malloc(sizeof(int) * 2);
			if (!new_collect)
				solong_exit(data, EXIT_FAILURE, "[ERROR]: malloc() failed.\n");
			new_collect[idx[1]][0] = data->collect_xy[idx[0]][0];
			new_collect[idx[1]++][1] = data->collect_xy[idx[0]][1];
		}
		free (data->collect_xy[idx[0]]);
		data->collect_xy[idx[0]] = NULL;
	}
	new_collect[idx[1]] = NULL;
	free (data->collect_xy);
	data->collect_xy = NULL;
	return (new_collect);
}

void	collect(t_solong *data)
{
	int	collected;

	collected = collect_idx(data);
	if (collected == -1)
		return ;
	data->map = collect_update_map(data);
	data->collect_xy = collect_update(data, collected);
	mlx_destroy_image(data->mlx->init, data->mlx->img);
	data->mlx->img_add = NULL;
	data->mlx->img_bpp = 0;
	data->mlx->img_end = 0;
	data->mlx->img_len = 0;
	data->mlx->img = mlx_new_image(data->mlx->init,
			data->win_xy[0], data->win_xy[1]);
	if (!data->mlx->img)
		solong_exit(data, EXIT_FAILURE, "[ERROR]: mlx_new_image() failed.\n");
	data->mlx->img_add = mlx_get_data_addr(data->mlx->img, &data->mlx->img_bpp,
			&data->mlx->img_len, &data->mlx->img_end);
	draw_map(data);
	return ;
}
