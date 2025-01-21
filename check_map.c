/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaouk <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-16 17:03:53 by machaouk          #+#    #+#             */
/*   Updated: 2025-01-16 17:03:53 by machaouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_walls(t_data *walls)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < walls->width)
	{
		if (walls->map[0][j] != '1' || walls->map[walls->height - 1][j] != '1')
			ft_msg_destroy(walls, "Error\nDown or up row has a non-wall.❌\n");
		j++;
	}
	while (i < walls->height)
	{
		if (walls->map[i][0] != '1' || walls->map[i][walls->width - 1] != '1')
			ft_msg_destroy(walls,
				"Error\nleft or right column has a non-wall.❌\n");
		i++;
	}
}

int	p_position(t_data *w)
{
	int	i;
	int	j;

	i = 0;
	w->p_x = -1;
	w->p_y = -1;
	w->p = 0;
	while (w->map && w->map[i] != NULL)
	{
		j = 0;
		while (w->map[i][j] != '\0')
		{
			if (w->map[i][j] == 'P')
			{
				w->p_x = i;
				w->p_y = j;
				w->p++;
			}
			j++;
		}
		i++;
	}
	if (w->p_x == -1 || w->p_y == -1)
		return (1);
	return (0);
}

int	ft_iselement(char elem)
{
	if (elem != 'E' && elem != 'P' && elem != 'M' && elem != 'C' && elem != '0'
		&& elem != '1')
		return (0);
	return (1);
}

int	characters(t_data *wl)
{
	int	i;
	int	j;

	i = 0;
	wl->c = 0;
	wl->e = 0;
	while (wl->map[i] != NULL)
	{
		j = 0;
		while (wl->map[i][j] != '\0' && wl->map[i][j] != '\n')
		{
			if (wl->map[i][j] == 'E')
				wl->e++;
			else if (wl->map[i][j] == 'C')
				wl->c++;
			else if (ft_iselement(wl->map[i][j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	if (wl->c == 0 || (wl->p > 1 || wl->p == 0) || (wl->e > 1 || wl->e == 0))
		return (1);
	return (0);
}

void	check_map(t_data *dt)
{
	dt->fd = open(dt->path, O_RDONLY);
	free(dt->path);
	if (dt->fd < 0)
	{
		close(dt->fd);
		ft_message("Can't open the file!❌\n");		
	}
	save_map(dt->fd, dt);
	check_walls(dt);
	if (p_position(dt) == 1)
		ft_message("missing 'P' in the Map.❌\n");
	if (characters(dt) == 1)
		ft_message("Repeated or Invalide character in the map.❌\n");
}
