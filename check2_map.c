/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaouk <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-16 17:04:40 by machaouk          #+#    #+#             */
/*   Updated: 2025/01/16 18:45:02 by machaouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **str, t_data *wl, int x, int y)
{
	if (x < 0 || y < 0 || y >= wl->width || x >= wl->height
		|| str[x][y] == '1' || str[x][y] == 'M' || str[x][y] == 'V')
		return ;
	if (str[x][y] == 'C')
		wl->collectable++;
	else if (str[x][y] == 'E')
	{
		wl->exit = 1;
		return ;
	}
	else if (str[x][y] == 'P')
		wl->player++;
	str[x][y] = 'V';
	flood_fill(str, wl, x + 1, y);
	flood_fill(str, wl, x - 1, y);
	flood_fill(str, wl, x, y + 1);
	flood_fill(str, wl, x, y - 1);
}

void	check2_map(t_data *data)
{
	char	**map_copy;

	map_copy = copy_map(data->map, data->height);
	if (map_copy == NULL)
		ft_msg_destroy(data, "Error\nFail to copy map!❌\n");
	data->collectable = 0;
	data->exit = 0;
	data->player = 0;
	flood_fill(map_copy, data, data->p_x, data->p_y);
	ft_free(map_copy);
	if (data->collectable != data->c || data->exit != data->e
		|| data->player != data->p)
		ft_msg_destroy(data,
			"Error\nThe map has isolated areas that are inaccessible.❌\n");
}

void	check_path(t_data *g, int argc, char *argv[])
{
	int	len;

	if (argc == 2)
	{
		if (open(argv[1], O_RDONLY) < 0)
			ft_message("The file is not created yet.❌\n");
		len = ft_strlen(argv[1]);
		if (ft_strcmp(argv[1] + (len - 4), ".ber") != 0)
			ft_message("Wrong extension.❌\n");
		g->path = ft_strdup(argv[1]);
	}
	else
		ft_message("Need argv[1].❌\n");
}
