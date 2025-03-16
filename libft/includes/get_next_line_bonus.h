/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:44:18 by smaitre           #+#    #+#             */
/*   Updated: 2025/03/02 02:58:09 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# define STR_MIN_SIZE 200

# include "project.h"
# include "libft.h"

typedef struct s_stash
{
	int				fd;
	ssize_t			len;
	char			*buffer;
	struct s_stash	*next;
}	t_stash;

typedef struct s_states
{
	size_t	buffer_len;
	size_t	read_len;
	size_t	pos;
	size_t	min_len;
	int		eol;
	char	*buffer;
}	t_states;

char	*get_next_line(int fd);
void	*clean_me(int rcode, t_states *sts, t_stash **stashes, t_stash *stash);
t_stash	*get_sfd(t_stash **stashes, int fd);
void	*remove_sfd(t_stash **stashes, t_stash *rstash);

#endif
