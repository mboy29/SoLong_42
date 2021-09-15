/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 12:15:22 by mboy              #+#    #+#             */
/*   Updated: 2021/09/03 12:17:55 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

void	solong_print(t_solong *data)
{
	int	idx;

	printf("MAP LEN : %d(x) - %d(y)\n", data->map_xy[0], data->map_xy[1]);
	printf("WIN xy : %d(x) - %d(y)\n", data->win_xy[0], data->win_xy[1]);
	printf("PLAY xy : %f(x) - %f(y)\n", data->player_xy[0], data->player_xy[1]);
	printf("EXIT xy : %d(x) - %d(y)\n", data->exit_xy[0], data->exit_xy[1]);
	printf("COLLECT : %d\n", data->collect);
	idx = -1;
	while (++idx < data->map_xy[1])
		printf("%s\n", data->map[idx]);
	idx = -1;
	while (data->collect_xy[++idx])
		printf("COLLECT %d : %d(x) - %d(y)\n", idx + 1,
			data->collect_xy[idx][0], data->collect_xy[idx][1]);
}

int	main(int ac, char **av)
{
	t_solong	*data;

	if (ac != 2)
	{
		ft_putstr("[ERROR]: usage ./so_long *map_path.\n");
		exit (EXIT_FAILURE);
	}
	data = init_solong();
	parse(data, av[1]);
	solong_loop(data);
	return (0);
}
