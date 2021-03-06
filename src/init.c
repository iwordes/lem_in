/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 12:11:59 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/01 15:40:52 by iwordes          ###   ########.fr       */
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
		error("No start point defined.");
	else if (a->heat == ~0U)
		error("No solution.");
	i = 0;
	while (i < ants)
		ant[i++] = a;
	ant[i] = NULL;
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
		error("No goal defined.");
	sort(room);
}

static void	val_antcnt(const char *ln)
{
	ITER(ln, ft_isdigit(*ln));
	if (*ln != 0)
		error("No ants given.");
}

void		init(t_room ***ant, t_room **room)
{
	char	*ln;
	size_t	a;

	if (ft_readln(0, &ln) <= 0)
	{
		free(ln);
		exit(1);
	}
	ft_putendl(ln);
	if ((a = ft_atou(ln)) == 0)
		error("No ants given.");
	val_antcnt(ln);
	free(ln);
	MGUARD(*ant = ZALT(t_room*, a + 1));
	;
	ps_rooms(&ln, room);
	ps_links(&ln, room);
	free(ln);
	;
	init_map(*room);
	init_ants(*ant, *room, a);
}
