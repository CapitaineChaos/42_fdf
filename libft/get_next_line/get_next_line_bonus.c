/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:44:24 by smaitre           #+#    #+#             */
/*   Updated: 2025/02/05 18:04:49 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line_bonus.h"

static int	refill_buffer(t_states *states, t_stash **stashes, t_stash *stash)
{
	char	*new_buffer;
	int		rd_len;

	if (states->buffer_len - states->pos < BUFFER_SIZE)
	{
		states->buffer_len += states->min_len;
		new_buffer = (char *)malloc((states->buffer_len) * sizeof (char));
		if (!new_buffer)
			return (1);
		ft_memcpy(new_buffer, states->buffer, states->pos);
		clean_me(2, states, stashes, stash);
		states->buffer = new_buffer;
	}
	if (!states->buffer)
		return (1);
	rd_len = read(stash->fd, states->buffer + states->pos, BUFFER_SIZE);
	if (rd_len == 0 && states->pos > 0)
	{
		states->eol = 1;
		return (0);
	}
	if (rd_len <= 0)
		return (1);
	states->read_len += rd_len;
	return (0);
}

static void	build_me(t_states *sts, t_stash **sths, t_stash *sth, int *rcode)
{
	if (sts->read_len - sts->pos <= 0)
	{
		*rcode = refill_buffer(sts, sths, sth);
		if (*rcode != 0)
			return ;
	}
	while (sts->eol == 0 && sts->read_len - sts->pos > 0)
	{
		if (sts->buffer[sts->pos] == '\n')
			sts->eol = 1;
		sts->pos++;
	}
	if (sts->eol && sts->read_len - sts->pos > 0)
	{
		clean_me(1, sts, sths, sth);
		sth->len = sts->read_len - sts->pos;
		sth->buffer = (char *)malloc(sth->len * sizeof (char));
		if (!sth->buffer)
		{
			*rcode = 1;
			return ;
		}
		ft_memcpy(sth->buffer, sts->buffer + sts->pos, sth->len);
	}
}

static int	pre_build_me(t_states *states, t_stash **stashes, t_stash *stash)
{
	char	*new_buffer;
	int		ret_code;

	ret_code = 0;
	new_buffer = NULL;
	if (stash->len > 0)
	{
		new_buffer = (char *)malloc(states->min_len * sizeof (char));
		if (!new_buffer)
			return (1);
		states->buffer_len = states->min_len;
		states->buffer = new_buffer;
		ft_memcpy(states->buffer, stash->buffer, stash->len);
		states->pos = 0;
		states->read_len = stash->len;
		clean_me(1, states, stashes, stash);
	}
	while (!ret_code && states->eol == 0)
		build_me(states, stashes, stash, &ret_code);
	return (ret_code);
}

static char	*my_gnl(t_states *states, t_stash **stashes, t_stash *stash)
{
	char	*ret;
	int		rcode;

	rcode = pre_build_me(states, stashes, stash);
	if (rcode)
		return (clean_me(0x7FFFFFFF, states, stashes, stash));
	ret = NULL;
	ret = (char *)malloc((states->pos + 1) * sizeof (char));
	if (!ret)
		return (clean_me(0x7FFFFFFF, states, stashes, stash));
	ft_memcpy(ret, states->buffer, states->pos);
	ret[states->pos] = '\0';
	clean_me(rcode | 32 | 16 | 8 | 2, states, stashes, stash);
	return (ret);
}

char	*get_next_line(int fd)
{
	static t_stash	*stashes;
	t_stash			*stash;
	t_states		states;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	stash = get_sfd(&stashes, fd);
	if (!stash)
		return (NULL);
	if (read(fd, 0, 0) < 0)
		return (remove_sfd(&stashes, stash));
	states.buffer = NULL;
	clean_me(56, &states, &stashes, stash);
	states.eol = 0;
	if (BUFFER_SIZE < STR_MIN_SIZE)
		states.min_len = STR_MIN_SIZE;
	else
		states.min_len = BUFFER_SIZE;
	if (!stash->buffer)
		clean_me(1, &states, &stashes, stash);
	return (my_gnl(&states, &stashes, stash));
}
