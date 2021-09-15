/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 12:25:30 by mboy              #+#    #+#             */
/*   Updated: 2021/09/07 14:46:13 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

t_key	*init_key(void)
{
	t_key	*key;

	key = malloc(sizeof(t_key));
	if (!key)
		return (NULL);
	key->exit = 0;
	key->up_zw = 0;
	key->down_ss = 0;
	key->right_qa = 0;
	key->left_dd = 0;
	return (key);
}

t_mlx	*init_mlx(void)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (NULL);
	mlx->init = NULL;
	mlx->win = NULL;
	mlx->img = NULL;
	mlx->img_add = NULL;
	mlx->img_bpp = 0;
	mlx->img_len = 0;
	mlx->img_end = 0;
	return (mlx);
}

t_text	*init_text(char idx, char *path, t_text *prev, t_text *next)
{
	t_text	*text;

	text = malloc(sizeof(t_text));
	if (!text)
		return (NULL);
	text->text = idx;
	text->path = ft_strdup(path);
	if (!text->path)
		return (NULL);
	text->img = NULL;
	text->img_add = NULL;
	text->img_bpp = 0;
	text->img_len = 0;
	text->img_end = 0;
	text->prev = prev;
	text->next = next;
	return (text);
}

t_idx	*init_idx(void)
{
	t_idx	*idx;

	idx = malloc(sizeof(t_mlx));
	if (!idx)
		return (NULL);
	idx->map_start[0] = 0;
	idx->map_start[1] = 0;
	idx->map_end[0] = 0;
	idx->map_end[1] = 0;
	idx->pix[0] = 0;
	idx->pix[1] = 0;
	return (idx);
}

t_solong	*init_solong(void)
{
	t_solong	*data;

	data = malloc(sizeof(t_solong));
	if (!data)
		solong_exit(NULL, EXIT_FAILURE, "[ERROR]: malloc() failed.\n");
	data->win_xy[0] = 0;
	data->win_xy[1] = 0;
	data->player_step = 0;
	data->player_xy[0] = 0.0;
	data->player_xy[1] = 0.0;
	data->exit_xy[0] = 0;
	data->exit_xy[1] = 0;
	data->map = NULL;
	data->map_xy[0] = 0;
	data->map_xy[1] = 0;
	data->collect = 0;
	data->collected = 0;
	data->collect_xy = NULL;
	data->text = NULL;
	data->mlx = init_mlx();
	data->key = init_key();
	data->idx = init_idx();
	if (!data->mlx || !data->key || !data->idx)
		solong_exit(NULL, EXIT_FAILURE, "[ERROR]: malloc() failed.\n");
	return (data);
}
