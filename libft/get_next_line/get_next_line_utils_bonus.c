/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:44:29 by smaitre           #+#    #+#             */
/*   Updated: 2025/03/12 18:23:24 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line_bonus.h"

t_stash	*get_sfd(t_stash **stashes, int fd)
{
	t_stash	*new_stash;
	t_stash	*tmp;

	tmp = *stashes;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	new_stash = (t_stash *)malloc(1 * sizeof(t_stash));
	if (!new_stash)
		return (NULL);
	new_stash->fd = fd;
	new_stash->buffer = NULL;
	new_stash->len = 0;
	new_stash->next = *stashes;
	*stashes = new_stash;
	return (new_stash);
}

void	*remove_sfd(t_stash **stashes, t_stash *rstash)
{
	t_stash	*stash;
	t_stash	*prev;

	if (!rstash)
		return (NULL);
	stash = *stashes;
	prev = NULL;
	while (stash)
	{
		if (stash->fd == rstash->fd)
		{
			if (prev == NULL)
				*stashes = stash->next;
			else
				prev->next = stash->next;
			if (stash->buffer)
				free(stash->buffer);
			free(stash);
			return (NULL);
		}
		prev = stash;
		stash = stash->next;
	}
	return (NULL);
}

void	*clean_me(int rcode, t_states *sts, t_stash **stashes, t_stash *stash)
{
	if ((rcode & 2) == 2)
	{
		if (sts->buffer)
			free(sts->buffer);
		sts->buffer = NULL;
	}
	if ((rcode & 8) == 8)
		sts->buffer_len = 0;
	if ((rcode & 16) == 16)
		sts->pos = 0;
	if ((rcode & 32) == 32)
		sts->read_len = 0;
	if (((rcode & 1) == 1) || ((rcode & 64) == 64))
	{
		if (stash->buffer)
			free(stash->buffer);
		stash->buffer = NULL;
		stash->len = 0;
	}
	if ((rcode & 64) == 64)
		remove_sfd(stashes, stash);
	return (NULL);
}
