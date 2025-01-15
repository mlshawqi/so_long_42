/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saait-si <saait-si@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 22:31:37 by saait-si          #+#    #+#             */
/*   Updated: 2024/04/30 17:29:05 by saait-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_count_windodw(t_point *app)
{
	char	*mvt;
	char	*num;

	num = ft_itoa(app->num_of_moves);
	mvt = ft_strjoin("moves : ", num);
	mlx_string_put(app->mlx, app->win, 10, 15, 0xFFFFFF, mvt);
	free(num);
	free(mvt);
}
