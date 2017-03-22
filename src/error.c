/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:16:22 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/21 18:21:02 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	error(const char *msg)
{
	ft_eprintf("\e[91m%s\e[0m\n", msg);
	exit(1);
}
