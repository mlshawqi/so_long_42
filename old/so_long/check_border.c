/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_border.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saait-si <saait-si@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 05:11:58 by saait-si          #+#    #+#             */
/*   Updated: 2024/05/02 23:20:06 by saait-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_del_newline(t_point *app)
{
	int		i;
	char	*temp;

	i = 0;
	while (app->dbl_ptr[i])
	{
		temp = app->dbl_ptr[i];
		app->dbl_ptr[i] = ft_strtrim(app->dbl_ptr[i], "\n");
		free(temp);
		i++;
	}
	return (app->dbl_ptr);
}

void	ft_border(t_point *app)
{
	int	j;
	int	i;

	j = 0;
	app->dbl_ptr = ft_del_newline(app);
	while ((app->dbl_ptr[0][j] != '\0' || app->dbl_ptr[app->h - 1][j] != '\0'))
	{
		if (app->dbl_ptr[0][j] != '1' || app->dbl_ptr[app->h - 1][j] != '1')
			exit_function("You need '1' for the border 🐸\n", app, 1);
		j++;
	}
	i = 0;
	map_width(app);
	while (app->dbl_ptr[i])
	{
		if (app->dbl_ptr[i][0] != '1' || app->dbl_ptr[i][app->w - 1] != '1')
			exit_function("you need 1 for the border (column) 🐸\n", app, 1);
		i++;
	}
}
