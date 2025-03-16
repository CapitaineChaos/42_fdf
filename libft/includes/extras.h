/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:06:28 by smaitre           #+#    #+#             */
/*   Updated: 2025/03/12 18:11:46 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTRAS_H
# define EXTRAS_H

# include "project.h"
# include "libft.h"

ssize_t	ft_cputchar_fd(char c, int fd);
ssize_t	ft_cputnchar_fd(char c, size_t nb, int fd);
ssize_t	ft_cputstrn_fd(char *s, size_t n, int fd);

ssize_t	ft_max(ssize_t a, ssize_t b);
ssize_t	ft_min(ssize_t a, ssize_t b);

char	*ft_utoa_base(size_t nb, char *base);
char	*ft_ltoa(long n);
int		ft_atoi_overflow(const char *str, int *res);

size_t	ft_nblen(long long int nb, size_t base_len);
size_t	ft_unblen(unsigned long long int nb, size_t base_len);

void	ft_strtolower(char *str);
void	ft_strtoupper(char *str);

char	**ft_split_charset(char const *s, const char *charset);
char	*ft_strchr_charset(const char *s, const char *charset);

t_bool	ft_issign(int c);

#endif