/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 12:11:59 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/19 20:18:49 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static void	init_ants(t_room **ant, t_room *room, size_t ants)
{
	t_room	*a;
	size_t	i;

	i = ~0;
	a = NULL;
	while (room[i += 1].name != NULL)
		if (room[i].type == 1)
		{
			a = room + i;
			break ;
		}
	if (a == NULL)
		ft_eprintf("\e[91mNo starting point!\e[0m\n"); // ISSUE
	i = 0;
	while (i < ants)
		ant[i++] = a;
}

static void	init_map(t_room *room)
{
	size_t	i;

	i = ~0;
	while (room[i += 1].name != NULL)
		if (room[i].type == 2)
		{
			heatmap(room + i);
			break ;
		}
	if (room[i].name == NULL)
		; // ISSUE
}

// What happens when no path to the dest is found?

void	init(t_room ***ant, t_room **room)
{
	char	*ln;
	size_t	a;

	if (ft_readln(0, &ln) <= 0)
	{
		free(ln);
		exit(1);
	}
	ft_putendl(ln);
	// TODO: ft_atoi / unsigned validation
	a = ABS(ft_atoi(ln));
	free(ln);
	MGUARD(*ant = ZALT(t_room*, a));
	;
	ps_rooms(&ln, room);
	ps_links(&ln, room);
	free(ln);
	;
	init_ants(*ant, *room, a);
	init_map(*room);

	sort(*room);
}
