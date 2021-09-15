/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 12:17:59 by mboy              #+#    #+#             */
/*   Updated: 2021/09/14 12:01:33 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

void	solong_exit(t_solong *data, int ex, char *mess)
{
	if (ex == -1 && !mess)
	{
		if ((int)data->player_xy[0] == data->exit_xy[0]
			&& (int)data->player_xy[1] == data->exit_xy[1]
			&& data->collect == 0)
		{
			ft_putstr(
				"[GAME] : End of game, all objects collected with a total of ");
			ft_putnbr(data->player_step);
			ft_putstr(" moves.\n");
			solong_exit(data, EXIT_SUCCESS,
				"[SUCCESS]: End of game, you have won.\n");
		}
		return ;
	}
	if (data->mlx->win)
	{
		mlx_destroy_window(data->mlx->init, data->mlx->win);
		data->mlx->win = NULL;
	}
	ft_putstr(mess);
	exit(ex);
}

void	solong_init(t_solong *data)
{
	data->mlx->init = mlx_init();
	if (!data->mlx)
		solong_exit(data, EXIT_FAILURE, "[ERROR]: mlx_init() failed.\n");
	if ((data->map_xy[0] * SQUARE) < 900)
		data->win_xy[0] = data->map_xy[0] * SQUARE;
	else
		data->win_xy[0] = 900;
	if ((data->map_xy[1] * SQUARE) < 700)
		data->win_xy[1] = data->map_xy[1] * SQUARE;
	else
		data->win_xy[1] = 700;
	data->mlx->win = mlx_new_window(data->mlx->init, data->win_xy[0],
			data->win_xy[1], "so_long");
	if (!data->mlx->win)
		solong_exit(data, EXIT_FAILURE, "[ERROR]: mlx_new_window() failed.\n");
	ft_putstr("[GAME]: Collect all");
	ft_putstr(" collectable objects to access the exit door.\n");
	return ;
}

void	solong_loop(t_solong *data)
{
	solong_init(data);
	mlx_hook(data->mlx->win, 2, (1L << 0), key_press, data);
	mlx_hook(data->mlx->win, 3, (1L << 1), key_release, data);
	mlx_hook(data->mlx->win, 17, 0, key_exit, data);
	mlx_loop_hook(data->mlx->init, solong, data);
	mlx_loop(data->mlx->init);
}

int	solong(t_solong *data)
{
	static int	init = 0;

	solong_exit(data, -1, NULL);
	if (data->key->press == 1)
		solong_exit(data, EXIT_SUCCESS, "[FAIL]: You ended the game.\n");
	if (init == 0)
	{
		text_images(data);
		init = 1;
	}
	collect(data);
	player(data);
	map(data);
	return (0);
}
