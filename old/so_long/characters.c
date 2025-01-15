/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   characters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saait-si <saait-si@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 05:15:18 by saait-si          #+#    #+#             */
/*   Updated: 2024/04/30 20:56:55 by saait-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_iselement(char elem)
{
	if (elem != 'E' && elem != 'P' && elem != 'C' && elem != '0' && elem != '1')
		return (0);
	return (1);
}

void	ft_check(t_point *app)
{
	int	i;
	int	j;

	i = 0;
	while (app->dbl_ptr[i])
	{
		j = 0;
		while (app->dbl_ptr[i][j])
		{
			if (ft_iselement(app->dbl_ptr[i][j]) == 0)
				exit_function("You have undefined character 🐸", app, 1);
			j++;
		}
		i++;
	}
	return ;
}

void	ft_chrcking_how_many_charteres(t_point *app)
{
	app->i = 0;
	app->p = 0;
	app->e = 0;
	app->j = 0;
	app->c_number = 0;
	while (app->dbl_ptr[app->i])
	{
		app->j = 0;
		while (app->dbl_ptr[app->i][app->j])
		{
			if (app->dbl_ptr[app->i][app->j] == 'P')
				app->p++;
			if (app->dbl_ptr[app->i][app->j] == 'C')
				app->c_number++;
			if (app->dbl_ptr[app->i][app->j] == 'E')
				app->e++;
			app->j++;
		}
		app->i++;
	}
	if (app->p > 1 || app->c_number == 0 || app->e > 1
		|| app->p == 0 || app->e == 0)
		exit_function("ReCheck 🅿️  or 🅲  or 🅴 !\n", app, 1);
}

char	**ft_map_copy(t_point *app)
{
	char	**map_copy;
	int		i;

	map_copy = malloc(sizeof(char *) * (app->h + 1));
	if (!map_copy)
		return (0);
	i = 0;
	while (app->dbl_ptr[i])
	{
		map_copy[i] = ft_strdup(app->dbl_ptr[i]);
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

void	p_position(char **map, int *array)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				array[0] = i;
				array[1] = j;
			}
			j++;
		}
		i++;
	}
}
