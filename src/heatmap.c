/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 12:09:34 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/21 16:47:05 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static void	recurse_(t_room *room, unsigned heat)
{
	size_t	i;

	if (room->heat <= heat)
		return ;
	i = ~0;
	room->heat = heat;
	room->heat_ = heat;
	while (room->exit[i += 1] != NULL)
		recurse_(room->exit[i], heat + 1);
}

void		heatmap(t_room *end)
{
	recurse_(end, 0);
}
