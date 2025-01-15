/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saait-si <saait-si@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:54:07 by saait-si          #+#    #+#             */
/*   Updated: 2024/04/30 19:03:22 by saait-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_point *app)
{
	int	width;
	int	height;

	app->ground = mlx_xpm_file_to_image(app->mlx, "textures/groundjwd.xpm",
			&width, &height);
	if (app->ground == NULL)
		exit_function("Image 1 (ground) can't load images ❌\n", app, 1);
	app->left = mlx_xpm_file_to_image(app->mlx,
			"textures/Pink_Monster_left.xpm", &width, &height);
	app->right = mlx_xpm_file_to_image(app->mlx,
			"textures/Pink_Monster_right.xpm", &width, &height);
	if (app->left == NULL || app->right == NULL)
		exit_function("Image 2 (player) can't load images ❌\n", app, 1);
	app->player = app->right;
	app->heart = mlx_xpm_file_to_image(app->mlx, "textures/heart1.xpm", &width,
			&height);
	if (app->heart == NULL)
		exit_function("Image 3 (heart) can't load images ❌\n", app, 1);
	app->exit = mlx_xpm_file_to_image(app->mlx, "textures/door.xpm", &width,
			&height);
	app->wall = mlx_xpm_file_to_image(app->mlx, "textures/wall_Purple.xpm",
			&width, &height);
	if (app->exit == NULL || app->wall == NULL)
		exit_function("Image 4 (exit) or (wall) can't load images ❌\n", app, 1);
}

void	change_player_direction(t_point *app)
{
	if (app->dj == -1)
		app->player = app->left;
	if (app->dj == 1)
		app->player = app->right;
	return ;
}

void	ft_c_number(t_point *app)
{
	app->num_of_moves++;
	ft_putnbr_fd(app->num_of_moves, 1);
	write(1, "\n", 1);
	return ;
}

void	change_player_position(t_point *app)
{
	int	array[2];

	p_position(app->dbl_ptr, array);
	if (app->dbl_ptr[array[0] + app->di][array[1] + app->dj] == '1')
		return ;
	if (app->dbl_ptr[array[0] + app->di][array[1] + app->dj] == 'C')
		app->c_number--;
	if (app->dbl_ptr[array[0] + app->di][array[1] + app->dj] == 'E'
		&& app->c_number == 0)
	{
		ft_c_number(app);
		exit_function("Congrats you won 🎉🥳\n", app, 0);
	}
	if (app->dbl_ptr[array[0] + app->di][array[1] + app->dj] == 'E'
		&& app->c_number != 0)
		return ;
	app->dbl_ptr[array[0]][array[1]] = '0';
	app->dbl_ptr[array[0] + app->di][array[1] + app->dj] = 'P';
	mlx_clear_window(app->mlx, app->win);
	if (app->di != 0 || app->dj != 0)
		ft_c_number(app);
	change_player_direction(app);
}

int	handle_keys(int keycode, t_point *app)
{
	app->di = 0;
	app->dj = 0;
	if (keycode == 65307)
		error("You exit my game 🙄\n");
	if (keycode == 126 || keycode == 13)
		app->di = -1;
	if (keycode == 65362)
		app->di = 1;
	if (keycode == 124 || keycode == 2)
		app->dj = 1;
	if (keycode == 123 || keycode == 0)
		app->dj = -1;
	change_player_position(app);
	draw_map(app);
	return (0);
}
