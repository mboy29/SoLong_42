/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 13:24:52 by mboy              #+#    #+#             */
/*   Updated: 2021/09/03 13:26:21 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

int	key_press(int keycode, t_solong *data)
{
	if (keycode == KEY_EXIT)
		solong_exit(data, EXIT_SUCCESS, "[FAIL]: You ended the game.\n");
	else if (keycode == KEY_UP)
		data->key->up_zw = 1;
	else if (keycode == KEY_DOWN)
		data->key->down_ss = 1;
	else if (keycode == KEY_RIGHT)
		data->key->right_qa = 1;
	else if (keycode == KEY_LEFT)
		data->key->left_dd = 1;
	return (0);
}

int	key_release(int keycode, t_solong *data)
{
	if (keycode == KEY_EXIT)
		solong_exit(data, EXIT_SUCCESS, "[FAIL]: You ended the game.\n");
	else if (keycode == KEY_UP)
		data->key->up_zw = 0;
	else if (keycode == KEY_DOWN)
		data->key->down_ss = 0;
	else if (keycode == KEY_RIGHT)
		data->key->right_qa = 0;
	else if (keycode == KEY_LEFT)
		data->key->left_dd = 0;
	return (0);
}

int	key_exit(t_solong *data)
{
	solong_exit(data, EXIT_SUCCESS, "[FAIL]: You ended the game.\n");
	return (0);
}
