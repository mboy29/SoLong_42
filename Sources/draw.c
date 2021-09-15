/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 13:12:06 by mboy              #+#    #+#             */
/*   Updated: 2021/09/08 18:47:06 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

void	draw_pixel(t_mlx *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->img_add + (y * img->img_len + x * (img->img_bpp / 8));
	*(unsigned int *)pixel = color;
	return ;
}

void	draw_map_basic(t_solong *data)
{
	int		idx[2];

	idx[0] = -1;
	data->idx->pix[0] = 0;
	while (++idx[0] < data->map_xy[0])
	{
		idx[1] = -1;
		data->idx->pix[1] = 0;
		while (++idx[1] < data->map_xy[1])
		{
			if (data->map[idx[1]][idx[0]] == 'E' && data->collect == 0)
				text_rescale(data, data->idx->pix[0], data->idx->pix[1], 'O');
			else if (data->map[idx[1]][idx[0]] != '0')
				text_rescale(data, data->idx->pix[0],
					data->idx->pix[1], data->map[idx[1]][idx[0]]);
			data->idx->pix[1] += SQUARE;
		}
		data->idx->pix[0] += SQUARE;
	}
	mlx_put_image_to_window(data->mlx->init,
		data->mlx->win, data->mlx->img, 0, 0);
	return ;
}

void	draw_map_limits(t_solong *data, int select)
{
	if (data->idx->map_start[select] < 0)
	{
		data->idx->map_end[select] += (data->idx->map_start[select] * -1);
		if (data->idx->map_end[select] > data->map_xy[select])
			data->idx->map_end[select] = data->map_xy[select] - 1;
		data->idx->map_start[select] = 0;
	}
	else if (data->idx->map_end[select] > data->map_xy[select] - 1)
	{
		data->idx->map_start[select] -= (data->idx->map_end[select]
				- (data->map_xy[select]));
		if (data->idx->map_start[select] < 0)
			data->idx->map_start[select] = 0;
		data->idx->map_end[select] = data->map_xy[select] - 1;
	}
	return ;
}

void	draw_map_idx(t_solong *data, int select)
{
	int	square[2];

	square[0] = data->win_xy[0] / SQUARE;
	square[1] = data->win_xy[1] / SQUARE;
	data->idx->pix[select] = 0;
	data->idx->map_start[select] = data->player_xy[select]
		- (square[select] / 2);
	if (select == 1 && data->win_xy[0] == 900 && data->win_xy[1] == 700)
		data->idx->map_end[select]
			= data->player_xy[select] + (square[select] / 2) + 1;
	else
		data->idx->map_end[select]
			= data->player_xy[select] + (square[select] / 2);
	draw_map_limits(data, select);
}

void	draw_map(t_solong *data)
{
	if (data->win_xy[0] < 900 && data->win_xy[1] < 700)
		return ((void)draw_map_basic(data));
	draw_map_idx(data, 0);
	while (data->idx->map_start[0] <= data->idx->map_end[0])
	{
		draw_map_idx(data, 1);
		while (data->idx->map_start[1] <= data->idx->map_end[1])
		{
			if (data->map[data->idx->map_start[1]][data->idx->map_start[0]]
					== 'E' && data->collect == 0)
				text_rescale(data, data->idx->pix[0], data->idx->pix[1], 'O');
			else if (data->map[data->idx->map_start[1]][data->idx->map_start[0]]
					!= '0')
				text_rescale(data, data->idx->pix[0], data->idx->pix[1],
					data->map[data->idx->map_start[1]]
				[data->idx->map_start[0]]);
			data->idx->map_start[1] += 1;
			data->idx->pix[1] += SQUARE;
		}
		data->idx->map_start[0] += 1;
		data->idx->pix[0] += SQUARE;
	}
	mlx_put_image_to_window(data->mlx->init,
		data->mlx->win, data->mlx->img, 0, 0);
}
