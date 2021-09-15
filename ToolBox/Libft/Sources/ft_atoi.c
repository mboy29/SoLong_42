/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 20:14:39 by mboy              #+#    #+#             */
/*   Updated: 2021/09/08 22:24:00 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_atoi(const char *str)
{
	long int	idx;
	long int	nbr;
	long int	neg;

	idx = 0;
	nbr = 0;
	neg = 1;
	while (str[idx] == ' ' || str[idx] == '\t' || str[idx] == '\n'
		|| str[idx] == '\v' || str[idx] == '\f' || str[idx] == '\r')
		idx++;
	if (str[idx] == '-' || str[idx] == '+')
	{
		if (str[idx] == '-')
			neg = -1;
		idx++;
	}
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		nbr = nbr * 10 + (str[idx] - 48);
		idx++;
	}
	return (nbr * neg);
}
