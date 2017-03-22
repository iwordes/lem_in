/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 12:11:51 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/21 18:54:20 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

#define EXIT room->exit[e]
#define PREXIT room->exit[e - 1]
#define DO_SORT PREXIT->heat > EXIT->heat
#define DO_SHUF PREXIT->heat > tmp->heat

void	sort(t_room *room)
{
	t_room	*tmp;
	size_t	e;

	while (room->name != NULL)
	{
		e = 1;
		while (PREXIT != NULL && EXIT != NULL)
		{
			if (DO_SORT)
			{
				tmp = EXIT;
				while (e > 0 && DO_SHUF)
				{
					EXIT = PREXIT;
					e -= 1;
				}
				EXIT = tmp;
			}
			e += 1;
		}
		room += 1;
	}
}
