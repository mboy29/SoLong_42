/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylibft.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 19:58:17 by mboy              #+#    #+#             */
/*   Updated: 2021/09/08 20:14:33 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include "./Sources/GNL/gnl.h"

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_str_isalpha(char *str);
int		ft_str_isdigit(char *str);
int		ft_str_isalnum(char *str);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
int		ft_strlen(const char *s);
int		ft_nblen(int n);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_tolower(int c);
int		ft_toupper(int c);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr(int n);

#endif
