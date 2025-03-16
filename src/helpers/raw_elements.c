/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raw_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:25:40 by smaitre           #+#    #+#             */
/*   Updated: 2025/03/16 00:27:42 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_elem	*get_last_elem(t_elem *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	append_elem(t_fdf *fdf, t_elem *new_elem)
{
	if (!fdf->map_raw)
		fdf->map_raw = new_elem;
	if (!fdf->last_raw_elem)
		fdf->last_raw_elem = new_elem;
	else
	{
		fdf->last_raw_elem->next = new_elem;
		fdf->last_raw_elem = new_elem;
	}
}
