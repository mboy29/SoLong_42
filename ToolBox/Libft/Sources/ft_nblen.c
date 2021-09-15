/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 20:18:45 by mboy              #+#    #+#             */
/*   Updated: 2021/09/08 20:19:01 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_nblen(int n)
{
	int	len;

	len = 0;
	if (n < 0 || n == 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}