/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 12:12:06 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/19 20:16:36 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

#define ANT ant[a]
#define EXIT (ANT->exit[e])

static bool	pathed(t_room **ant)
{
	size_t	a;

	a = ~0;
	while (ant[a += 1] != NULL)
		if (ANT->heat != 0)
			return (false);
	return (true);
}

static bool	ant_in_room(t_room **ant, t_room *room)
{
	size_t	a;

	if (room->heat == 0)
		return (false);
	a = ~0;
	while (ant[a += 1] != NULL)
		if (ANT == room)
			return (true);
	return (false);
}

static void	print_move(size_t ant, t_room *to)
{
	static size_t	i;

	if (to == NULL)
	{
		// NOTE: Leave out for temp. debug reasons
		//if (i != 0)
			write(1, "\n", 1);
		i = 0;
	}
	else
	{
		if (i != 0)
			write(1, " ", 1);
		ft_printf("L%zu-%s", ant + 1, to->name);
		i += 1;
	}
}

void		path(t_room **ant)
{
	size_t	a;
	size_t	e;

	ft_eprintf("Pathing...\n");
	while (!pathed(ant))
	{
		a = ~0;
		while (ant[a += 1] != NULL)
		{
			e = ~0;
			ft_eprintf("Ant\n");
			while (ANT->exit[e += 1] != NULL)
			{
				if (EXIT->heat <= ANT->heat && !ant_in_room(ant, EXIT))
				{
					print_move(a, EXIT);
					ANT = EXIT;
					break ;
				}
			}
			ft_eprintf("No ant\n");
		}
		print_move(~0, NULL);
	}
	ft_eprintf("Complete!\n");
}
