/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:49:51 by mboy              #+#    #+#             */
/*   Updated: 2021/09/08 18:45:37 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

char	**player_update_map(t_solong *data, char **new_map)
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
			if (data->map[idx[0]][idx[1]] == 'P')
				new_map[idx[0]][idx[1]] = '0';
			else
				new_map[idx[0]][idx[1]] = data->map[idx[0]][idx[1]];
		}
		new_map[idx[0]][idx[1]] = '\0';
		free (data->map[idx[0]]);
		data->map[idx[0]] = NULL;
	}
	new_map[idx[0]] = NULL;
	if (new_map[(int)data->player_xy[1]][(int)data->player_xy[0]] != 'E')
		new_map[(int)data->player_xy[1]][(int)data->player_xy[0]] = 'P';
	return (new_map);
}

void	player_move_count(t_solong *data, double player_x, double player_y)
{
	if ((player_x != data->player_xy[0] || player_y != data->player_xy[1])
		&& ((int)player_x != (int)data->player_xy[0]
			|| (int)player_y != (int)data->player_xy[1]))
	{
		data->player_step += 1;
		ft_putstr("[GAME]: ");
		ft_putnbr(data->player_step);
		if (data->player_step == 1)
			ft_putstr(" move.\n");
		else
			ft_putstr(" moves.\n");
	}
	return ;
}

void	player_move_exit(t_solong *data)
{
	if (data->key->up_zw == 1 && data->map[(int)(data->player_xy[1] - 0.1)]
			[(int)data->player_xy[0]] != '1')
		data->player_xy[1] -= 0.1;
	else if (data->key->down_ss == 1
		&& data->map[(int)(data->player_xy[1] + 0.1)]
		[(int)data->player_xy[0]] != '1')
		data->player_xy[1] += 0.1;
	else if (data->key->right_qa == 1 && data->map[(int)data->player_xy[1]]
		[(int)(data->player_xy[0] + 0.1)] != '1')
		data->player_xy[0] += 0.1;
	else if (data->key->left_dd == 1 && data->map[(int)data->player_xy[1]]
		[(int)(data->player_xy[0] - 0.1)] != '1')
		data->player_xy[0] -= 0.1;
	return ;
}

void	player_move(t_solong *data)
{
	if (data->key->up_zw == 1 && data->map[(int)(data->player_xy[1] - 0.1)]
		[(int)data->player_xy[0]] != '1' && (data->map[(int)
		(data->player_xy[1] - 0.1)][(int)data->player_xy[0]] != 'E'))
		data->player_xy[1] -= 0.1;
	else if (data->key->down_ss == 1 && data->map[(int)
			(data->player_xy[1] + 0.1)][(int)data->player_xy[0]] != '1'
		&& (data->map[(int)(data->player_xy[1] + 0.1)]
		[(int)data->player_xy[0]] != 'E'))
		data->player_xy[1] += 0.1;
	else if (data->key->right_qa == 1 && data->map[(int)
			data->player_xy[1]][(int)(data->player_xy[0] + 0.1)] != '1'
		&& (data->map[(int)data->player_xy[1]][(int)
		(data->player_xy[0] + 0.1)] != 'E'))
		data->player_xy[0] += 0.1;
	else if (data->key->left_dd == 1 && data->map[(int)
			data->player_xy[1]][(int)(data->player_xy[0] - 0.1)] != '1'
		&& (data->map[(int)data->player_xy[1]][(int)
		(data->player_xy[0] - 0.1)] != 'E'))
		data->player_xy[0] -= 0.1;
	return ;
}

void	player(t_solong *data)
{
	char		**new_map;
	double		player[2];

	player[0] = data->player_xy[0];
	player[1] = data->player_xy[1];
	player_move(data);
	if (data->collect > 0)
		player_move(data);
	else
		player_move_exit(data);
	player_move_count(data, player[0], player[1]);
	new_map = malloc(sizeof(char *) * (data->map_xy[1] + 1));
	if (!new_map)
		solong_exit(data, EXIT_FAILURE, "[ERROR]: malloc() failed.\n");
	new_map = player_update_map(data, new_map);
	free (data->map);
	data->map = NULL;
	data->map = new_map;
	return ;
}
