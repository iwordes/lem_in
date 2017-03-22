/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 12:12:06 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/21 17:58:31 by iwordes          ###   ########.fr       */
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

static void	print_move(size_t ant, t_room *to)
{
	static size_t	i;

	if (to == NULL)
	{
		if (i != 0)
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

	while (!pathed(ant))
	{
		a = ~0;
		while (ant[a += 1] != NULL)
		{
			e = ~0;
			while (ANT->exit[e += 1] != NULL)
			{
				if (EXIT->heat <= ANT->heat)
				{
					print_move(a, EXIT);
					ANT->heat = ANT->heat_;
					ANT = EXIT;
					if (ANT->heat != 0)
						ANT->heat = ~0U;
					break ;
				}
			}
		}
		print_move(~0, NULL);
	}
}
