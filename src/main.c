/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 12:12:02 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/19 20:09:49 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int		main(void)
{
	t_room	**ant;
	t_room	*room;
	size_t	i;

	init(&ant, &room);

	// DEBUG
	//ft_eprintf("\e[95mSorted Rooms:\n");
	//for (int R = 0; room[R].name != NULL; R += 1)
	//{
	//	ft_eprintf("%s: %u\n", room[R].name, room[R].heat);
	//	for (int E = 0; room[R].exit[E] != NULL; E += 1)
	//		ft_eprintf("\e[35m-> %s: %zu\e[95m\n", room[R].exit[E]->name, room[R].exit[E]->heat);
	//}
	//ft_eprintf("\e[91mEND DEBUG\e[0m\n");
	// DEBUG

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
