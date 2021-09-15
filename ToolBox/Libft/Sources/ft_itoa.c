/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 20:18:30 by mboy              #+#    #+#             */
/*   Updated: 2021/09/08 22:24:54 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_len(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i = 1;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_strcpy(int n, char *src)
{
	int		idx;
	char	*dst;

	idx = -1;
	if (n == -2147483648)
	{
		dst = malloc(sizeof(char) * 12);
		if (!dst)
			return (NULL);
	}
	if (n == 2147483647)
	{
		dst = malloc(sizeof(char) * 11);
		if (!dst)
			return (NULL);
	}
	while (src[++idx])
		dst[idx] = src[idx];
	dst[idx] = '\0';
	return (dst);
}

static char	*ft_limits(int n)
{
	if (n == 2147483647)
		return (ft_strcpy(n, "2147483647"));
	return (ft_strcpy(n, "-2147483648"));
}

int	ft_terner(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

char	*ft_itoa(int n)
{
	int		nb;
	int		len;
	char	*str;

	if (n == -2147483648 || n == 2147483647)
		return (ft_limits(n));
	nb = ft_terner(n);
	len = ft_len(nb);
	if (n < 0)
		len++;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (nb > 0)
	{
		str[--len] = (nb % 10) + 48;
		nb = nb / 10;
	}
	if (n < 0)
		str[0] = '-';
	else if (n == 0)
		str[0] = '0';
	return (str);
}
