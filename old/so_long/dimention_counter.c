/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimention_counter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saait-si <saait-si@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:16:51 by saait-si          #+#    #+#             */
/*   Updated: 2024/04/30 15:01:46 by saait-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_height(t_point *app)
{
	app->h = 0;
	while (app->dbl_ptr[app->h])
		app->h++;
	if (!app->h)
		exit_function("Your file is empty 🤡", app, 1);
	return (app->h);
}

int	len_to_new_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
	{
		i++;
	}
	return (i);
}

void	map_width(t_point *app)
{
	int	i;

	app->w = len_to_new_line(app->dbl_ptr[0]);
	i = 0;
	while (app->dbl_ptr[i])
	{
		if (app->w != len_to_new_line(app->dbl_ptr[i]))
			exit_function("Width error 🐸\n", app, 1);
		i++;
	}
}
