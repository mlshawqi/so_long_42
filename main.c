/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaouk <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-15 22:19:38 by machaouk          #+#    #+#             */
/*   Updated: 2025/01/16 18:41:09 by machaouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_data	game;

	put_null(&game);
	check_path(&game, argc, argv);
	check_map(&game);
	check2_map(&game);
	game.mlx = mlx_init();
	if (game.mlx == NULL)
		ft_msg_destroy(&game, "Error: mlx_init failed\n");
	game.win = mlx_new_window(game.mlx, game.width * 50, game.height * 50,
			"swan");
	if (game.win == NULL)
		ft_msg_destroy(&game, "Error: mlx_new_window failed\n");
	load_image(&game);
	load_animation(&game);
	ft_load_player(&game);
	ft_draw_map(&game);
	mlx_hook(game.win, 2, 1L << 0, ft_close, &game);
	mlx_hook(game.win, 17, 0, handle_window_close, &game);
	mlx_loop(game.mlx);
	ft_destroy(&game);
}
