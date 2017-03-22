/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 12:48:12 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/21 18:17:12 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include <libft.h>
#include <stdlib.h>

#define MGUARD(MEM) if ((MEM) == NULL) exit(12)

typedef struct		s_room
{
	char			*name;
	unsigned		heat;
	unsigned		heat_;
	unsigned		type;
	struct s_room	**exit;
}					t_room;

void				error(const char *msg);

void				init(t_room ***ant, t_room **room);
void				heatmap(t_room *goal);
void				sort(t_room *room);
void				path(t_room **ant);

void				ps_rooms(char **ln, t_room **room);
void				ps_links(char **ln, t_room **room);

#endif
