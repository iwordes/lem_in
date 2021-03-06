/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 12:35:21 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/11 17:43:12 by iwordes          ###   ########.fr       */
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

static bool	check_room(const char *ln)
{
	if (*ln == ' ')
		return (false);
	ITER(ln, *ln != ' ');
	ITER(ln, *ln == ' ');
	if (!ft_isdigit(*ln))
		return (false);
	ITER(ln, ft_isdigit(*ln));
	ITER(ln, *ln == ' ');
	if (!ft_isdigit(*ln))
		return (false);
	ITER(ln, ft_isdigit(*ln));
	return (*ln == 0);
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
			ft_strequ(*ln, "##start") && (type = 1);
			ft_strequ(*ln, "##end") && (type = 2);
			ft_putendl(*ln);
			free(*ln);
			continue ;
		}
		if (ft_charcnt(*ln, '-') > 0)
			return ;
		else if (ft_charcnt(*ln, ' ') != 2 || !check_room(*ln))
			error("Invalid room definition: Format error.");
		else if (ft_struntil(*ln, ' ') == 0)
			error("Invalid room definition: Empty name.");
		push_room(room, *ln, type);
		ft_putendl(*ln);
		free(*ln);
		type = 0;
	}
}
