/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaouk <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-15 22:19:24 by machaouk          #+#    #+#             */
/*   Updated: 2025/01/16 11:26:47 by machaouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_message(char *msg)
{
	write(1, "Error\n", 6);
	write(1, msg, ft_strlen(msg));
	exit(0);
}

void	ft_destroy(t_data *d)
{
	textures(d);
	close(d->fd);
	if (d->mlx && d->win)
		mlx_destroy_window(d->mlx, d->win);
	if (d->mlx)
	{
		mlx_destroy_display(d->mlx);
		free(d->mlx);		
	}
	if (d->map)
		ft_free(d->map);
	exit(0);
}

void	ft_msg_destroy(t_data *data, char *msg)
{
	write(1, msg, ft_strlen(msg));
	textures(data);
	close(data->fd);
	if (data->mlx && data->win)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (data->map)
		ft_free(data->map);
	exit(0);
}

void	textures(t_data *t)
{
	if (t->f_exit[0])
		mlx_destroy_image(t->mlx, t->f_exit[0]);
	if (t->f_exit[1])
		mlx_destroy_image(t->mlx, t->f_exit[1]);
	if (t->f_player_r[0])
		mlx_destroy_image(t->mlx, t->f_player_r[0]);
	if (t->f_player_r[1])
		mlx_destroy_image(t->mlx, t->f_player_r[1]);
	if (t->f_player_l[0])
		mlx_destroy_image(t->mlx, t->f_player_l[0]);
	if (t->f_player_l[1])
		mlx_destroy_image(t->mlx, t->f_player_l[1]);
	if (t->frame_collectable[0])
		mlx_destroy_image(t->mlx, t->frame_collectable[0]);
	if (t->frame_collectable[1])
		mlx_destroy_image(t->mlx, t->frame_collectable[1]);
	if (t->frame_enemy[0])
		mlx_destroy_image(t->mlx, t->frame_enemy[0]);
	if (t->frame_enemy[1])
		mlx_destroy_image(t->mlx, t->frame_enemy[1]);
	if (t->i_background)
		mlx_destroy_image(t->mlx, t->i_background);
	if (t->i_wall)
		mlx_destroy_image(t->mlx, t->i_wall);
}

void	put_null(t_data *game)
{
	game->path = NULL;
	game->movement = 0;
	game->height = 0;
	game->width = 0;
	game->collecting = 0;
	game->butterfly_r = 0;
	game->current_frame = 0;
	game->n_move = NULL;
	game->map = NULL;
	game->mlx = NULL;
	game->win = NULL;
	game->f_exit[0] = NULL;
	game->f_exit[1] = NULL;
	game->f_player_l[0] = NULL;
	game->f_player_l[1] = NULL;
	game->f_player_r[0] = NULL;
	game->f_player_r[1] = NULL;
	game->frame_collectable[0] = NULL;
	game->frame_collectable[1] = NULL;
	game->frame_enemy[0] = NULL;
	game->frame_enemy[1] = NULL;
	game->i_background = NULL;
	game->i_wall = NULL;
}
