/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 12:34:24 by iwordes           #+#    #+#             */
/*   Updated: 2017/04/11 14:49:51 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static void		push_link(t_room *room, t_room *link)
{
	t_room	**tmp;
	size_t	i;

	i = ~0;
	while (room->exit[i += 1] != NULL)
		if (room->exit[i] == link)
			return ;
	MGUARD(tmp = ZALT(t_room*, i + 2));
	ft_memcpy(tmp, room->exit, sizeof(t_room*) * i);
	free(room->exit);
	room->exit = tmp;
	tmp[i] = link;
}

#define NAME (*room)[i].name

static t_room	*find_room(t_room **room, char *name)
{
	size_t	i;
	size_t	l;

	i = ~0;
	l = ft_struntil(name, '-');
	while ((*room)[i += 1].name != NULL)
		if (ft_strnequ(name, NAME, l) && NAME[l] == 0)
			return (*room + i);
	return (NULL);
}

#define R1 (find_room(room, *ln))
#define R2 (find_room(room, ft_strchr(*ln, '-') + 1))

void			ps_links(char **ln, t_room **room)
{
	t_room	*r1;
	t_room	*r2;

	while (1)
	{
		ft_putendl(*ln);
		if ((*ln)[0] != '#')
		{
			if (ft_charcnt(*ln, '-') != 1)
				error("Invalid link definition.");
			r1 = R1;
			r2 = R2;
			if (r1 == NULL || r2 == NULL)
				error("Cannot link nonexistent rooms.");
			push_link(r1, r2);
			push_link(r2, r1);
		}
		free(*ln);
		if (ft_readln(0, ln) <= 0)
			return ;
	}
}
