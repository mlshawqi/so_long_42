/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saait-si <saait-si@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 09:35:22 by saait-si          #+#    #+#             */
/*   Updated: 2024/04/30 17:55:37 by saait-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_flood_fill(char **map, int i, int j)
{
	if (map[i][j] == '1' || map[i][j] == 'A')
		return ;
	if (map[i][j] == 'E')
	{
		map[i][j] = 'A';
		return ;
	}
	map[i][j] = 'A';
	ft_flood_fill(map, i - 1, j);
	ft_flood_fill(map, i + 1, j);
	ft_flood_fill(map, i, j + 1);
	ft_flood_fill(map, i, j - 1);
}

void	chack_flood_fill(char **map, t_point *app)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				exit_function("	 error map 🐸\n", app, 1);
			j++;
		}
		i++;
	}
}

void	ft_checking_path(t_point *app)
{
	char	**copy_map;
	int		array[2];
	// int		i;

	// i = 0;
	copy_map = ft_map_copy(app);
	p_position(copy_map, array);
	ft_flood_fill(copy_map, array[0], array[1]);
	chack_flood_fill(copy_map, app);
	ft_dbl_free(copy_map);
}
