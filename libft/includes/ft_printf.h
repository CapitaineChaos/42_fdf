/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:39:34 by smaitre           #+#    #+#             */
/*   Updated: 2024/12/24 16:59:16 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include "extras.h"
# include "project.h"

typedef struct s_flags
{
	uint8_t	dash;
	uint8_t	zero;
	uint8_t	sharp;
	uint8_t	space;
	uint8_t	plus;
}	t_flags;

typedef struct s_format
{
	t_flags	flags;
	char	argtype;
	char	sign;
	char	fill;
	char	hex;
	size_t	newstr_len;
	size_t	nb_len;
	size_t	copy_len;
	size_t	width;
	size_t	nb_before;
	size_t	nb_after;
	ssize_t	precision;
}	t_format;

typedef void	(*t_handlefct)(va_list args, t_format *ft, int *count);

void	process_chr(va_list args, t_format *ft, int *count);
void	process_ptr(va_list args, t_format *ft, int *count);
void	process_str(va_list args, t_format *ft, int *count);
void	process_nbr(va_list args, t_format *ft, int *count);
void	process_unb(va_list args, t_format *ft, int *count);
void	process_hex(va_list args, t_format *ft, int *count);
void	process_pct(va_list args, t_format *ft, int *count);

size_t	simple_str(const char	*str, int *count);

void	apply_str(const char *str, t_format *ft, int *count);
void	apply_hex(unsigned long long nb, t_format *ft, int *count);
void	apply_nbr(long nb, t_format *ft, int *count);

void	set_strparams(size_t len, ssize_t precision, t_format *ft);
void	set_nbrparams(int flag, t_format *ft);

int		ft_printf(const char *str, ...);

typedef struct s_env
{
	int	count;
	int	fd;
}	t_env;

typedef void	(*t_handlefct_fd)(va_list args, t_format *ft, t_env *env);

void	process_chr_fd(va_list args, t_format *ft, t_env *env);
void	process_ptr_fd(va_list args, t_format *ft, t_env *env);
void	process_str_fd(va_list args, t_format *ft, t_env *env);
void	process_nbr_fd(va_list args, t_format *ft, t_env *env);
void	process_unb_fd(va_list args, t_format *ft, t_env *env);
void	process_hex_fd(va_list args, t_format *ft, t_env *env);
void	process_pct_fd(va_list args, t_format *ft, t_env *env);

size_t	simple_str_fd(const char	*str, t_env *env);

void	apply_str_fd(const char *str, t_format *ft, t_env *env);
void	apply_hex_fd(unsigned long long nb, t_format *ft, t_env *env);
void	apply_nbr_fd(long nb, t_format *ft, t_env *env);

void	set_strparams_fd(size_t len, ssize_t precision, t_format *ft);
void	set_nbrparams_fd(int flag, t_format *ft);

int		ft_printf_fd(int fd, const char *str, ...);

#endif
