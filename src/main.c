/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 12:12:02 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/20 19:52:29 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

#include <fcntl.h>
int		main(int argc, char **argv)
{
	t_room	**ant;
	t_room	*room;
	size_t	i;

	///
	ft_printf("\e[91mUSING dup2() TO LOAD FILES AS STDIN\e[0m\n");
	if (argc == 2)
		dup2(open(argv[1], O_RDONLY), 0);
	///

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
