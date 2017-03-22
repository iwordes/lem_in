/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 12:35:21 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/21 19:00:01 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

#define ROOM (*rooms)[i]

static void	push_room(t_room **rooms, char *name, int type)
{
	t_room	*tmp;
	size_t	p2;
	size_t	i;

	i = 0;
	while (ROOM.name != NULL)
		if (ft_strequ(ROOM.name, name))
			error("Duplicate room definitions.");
		else
			i += 1;
	p2 = 2;
	while (i + 1 >= (p2 *= 2))
		if (i + 1 == p2)
		{
			MGUARD(tmp = ZALT(t_room, sizeof(t_room) * p2 * 2));
			ft_memcpy(tmp, *rooms, sizeof(t_room) * p2);
			free(*rooms);
			*rooms = tmp;
			break ;
		}
	ROOM.heat = ~0;
	ROOM.type = type;
	MGUARD(ROOM.exit = ZALT(t_room*, 4));
	MGUARD(ROOM.name = ft_strsub(name, 0, ft_struntil(name, ' ')));
}

void		ps_rooms(char **ln, t_room **room)
{
	int		type;

	type = 0;
	MGUARD(*room = ZALT(t_room, 4));
	while (ft_readln(0, ln) > 0)
	{
		if ((*ln)[0] == '#')
		{
			if (ft_strequ(*ln, "##start"))
				type = 1;
			else if (ft_strequ(*ln, "##end"))
				type = 2;
			ft_putendl(*ln);
			continue ;
		}
		if (ft_charcnt(*ln, '-') > 0)
			return ;
		else if (ft_charcnt(*ln, ' ') != 2)
			error("Invalid room definition: Format error.");
		else if (ft_struntil(*ln, ' ') == 0)
			error("Invalid room definition: Empty name.");
		push_room(room, *ln, type);
		ft_putendl(*ln);
		free(*ln);
		type = 0;
	}
}
