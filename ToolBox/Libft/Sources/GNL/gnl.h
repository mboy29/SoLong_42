/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 19:57:38 by mboy              #+#    #+#             */
/*   Updated: 2021/09/08 19:58:09 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

int		gnl(int fd, char **line);
char	*gnl_line(char *line, int size, int letter);

#endif
