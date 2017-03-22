/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 12:12:02 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/21 18:56:21 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int		main(void)
{
	t_room	**ant;
	t_room	*room;
	size_t	i;

	init(&ant, &room);
	write(1, "\n", 1);
	path(ant);
	;
	i = ~0;
	free(ant);
	while (room[i += 1].name != NULL)
	{
		free(room[i].name);
		free(room[i].exit);
	}
	free(room);
}
