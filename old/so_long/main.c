/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saait-si <saait-si@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 23:16:06 by saait-si          #+#    #+#             */
/*   Updated: 2024/04/30 20:53:39 by saait-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_point *app)
{
	exit_function("You exit my game 🙄", app, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_point	app;

	validation_extantion(&app, ac, av);
	validation_exist(&app);
	app.dbl_ptr = read_map(&app);
	map_width(&app);
	map_height(&app);
	ft_border(&app);
	ft_check(&app);
	ft_chrcking_how_many_charteres(&app);
	ft_checking_path(&app);
	app.mlx = mlx_init();
	app.win = mlx_new_window(app.mlx, app.w * 30, map_height(&app) * 30,
			"Dima maghreb");
	load_images(&app);
	draw_map(&app);
	//mlx_hook(app.win, 17, 0, exit_game, &app);
	mlx_hook(app.win, 2, 1L<<0, handle_keys, &app);
	mlx_loop(app.mlx);
	return (0);
}
