/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 20:23:49 by mboy              #+#    #+#             */
/*   Updated: 2021/09/08 20:24:23 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		idx[2];
	char	*join;

	idx[0] = 0;
	idx[1] = 0;
	if (!s1 && !s2)
		return (NULL);
	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)));
	if (!join)
		return (NULL);
	while (s1[idx[0]])
	{
		join[idx[0]] = s1[idx[0]];
		idx[0]++;
	}
	while (s2[idx[1]])
	{
		join[idx[0] + idx[1]] = s2[idx[1]];
		idx[1]++;
	}
	join[idx[0] + idx[1]] = '\0';
	return (join);
}
