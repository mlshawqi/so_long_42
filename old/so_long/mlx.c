/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saait-si <saait-si@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 22:06:19 by saait-si          #+#    #+#             */
/*   Updated: 2024/04/30 16:20:39 by saait-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_map(t_point *app, int j, int i)
{
	while (app->dbl_ptr[i][j])
	{
		if (app->dbl_ptr[i][j] == '0')
		mlx_put_image_to_window(app->mlx, app->win, app->ground, j * 30, i
			* 30);
		if (app->dbl_ptr[i][j] == 'P')
			mlx_put_image_to_window(app->mlx, app->win, app->player, j * 30, i
				* 30);
		if (app->dbl_ptr[i][j] == 'E')
			mlx_put_image_to_window(app->mlx, app->win, app->exit, j * 30, i
				* 30);
		if (app->dbl_ptr[i][j] == 'C')
			mlx_put_image_to_window(app->mlx, app->win, app->heart, j * 30, i
				* 30);
		if (app->dbl_ptr[i][j] == '1')
			mlx_put_image_to_window(app->mlx, app->win, app->wall, j * 30, i
				* 30);
		j++;
	}
}

void	draw_map(t_point *app)
{
	int	i;
	int	j;

	i = 0;
	while (app->dbl_ptr[i])
	{
		j = 0;
		ft_draw_map(app, j, i);
		i++;
		ft_count_windodw(app);
	}
}
