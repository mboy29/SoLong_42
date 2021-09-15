/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 13:32:00 by mboy              #+#    #+#             */
/*   Updated: 2021/09/07 15:05:42 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

void	text_list(t_solong *data, char text, char *path)
{
	data->text->next = init_text(text, path, data->text, NULL);
	if (!data->text->next)
		solong_exit(data, EXIT_FAILURE, "[ERROR]: malloc() failed.\n");
	data->text = data->text->next;
	return ;
}

void	text_images_struct(t_solong *data)
{
	data->text_c[0] = 'P';
	data->text_c[1] = '1';
	data->text_c[2] = 'E';
	data->text_c[3] = 'C';
	data->text_c[4] = 'O';
	data->text_path[0] = "./Textures/player.xpm";
	data->text_path[1] = "./Textures/wall.xpm";
	data->text_path[2] = "./Textures/exit_close.xpm";
	data->text_path[3] = "./Textures/collect.xpm";
	data->text_path[4] = "./Textures/exit_open.xpm";
	return ;
}

void	text_images(t_solong *data)
{
	int		idx;
	int		size;

	size = 64;
	idx = -1;
	text_images_struct(data);
	while (++idx < 5)
	{
		if (idx == 0)
			data->text = init_text(data->text_c[idx],
					data->text_path[idx], NULL, NULL);
		else
			text_list(data, data->text_c[idx], data->text_path[idx]);
		data->text->img = mlx_xpm_file_to_image(data->mlx->init,
				data->text->path, &size, &size);
		if (!data->text->img)
			solong_exit(data, EXIT_FAILURE,
				"[ERROR]: Convert xpm to image failed.\n");
		data->text->img_add = mlx_get_data_addr(data->text->img,
				&data->text->img_bpp, &data->text->img_len,
				&data->text->img_end);
	}
	while (data->text->prev != NULL)
		data->text = data->text->prev;
	return ;
}

unsigned int	text_color(t_solong *data, int text_x, int text_y)
{
	char	*ptr;

	ptr = data->text->img_add + ((text_y * data->text->img_len)
			+ (text_x * (data->text->img_bpp / 8)));
	if (!ptr)
		solong_exit(data, EXIT_FAILURE, "[ERROR]: Rescaling failed!\n");
	return (*(unsigned int *)ptr);
}

void	text_rescale(t_solong *data, int start_x, int start_y, char text)
{
	int		idx[2];
	int		color;

	idx[0] = -1;
	if (data->text->text != text)
	{
		while (data->text->text != text)
			data->text = data->text->next;
	}
	while (++idx[0] < SQUARE && (idx[0] + start_x) < data->win_xy[0])
	{
		idx[1] = -1;
		while (++idx[1] < SQUARE && (idx[1] + start_y) < data->win_xy[1])
		{
			color = text_color(data, idx[0], idx[1]);
			draw_pixel(data->mlx, (idx[0] + start_x),
				(idx[1] + start_y), color);
		}
	}
	if (data->text->prev != NULL)
	{
		while (data->text->prev != NULL)
			data->text = data->text->prev;
	}
	return ;
}
