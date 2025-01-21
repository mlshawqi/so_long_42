/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                       :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: machaouk <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-15 22:19:44 by machaouk          #+#    #+#             */
/*   Updated: 2025/01/16 10:57:45 by machaouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_image(t_data *data)
{
	data->i_background = mlx_xpm_file_to_image(data->mlx,
			"textures/background.xpm", &(int){0}, &(int){0});
	if (!data->i_background)
		ft_msg_destroy(data, "Failed to load frame of background\n");
	data->i_wall = mlx_xpm_file_to_image(data->mlx, "textures/wall.xpm",
			&(int){0}, &(int){0});
	if (!data->i_wall)
		ft_msg_destroy(data, "Failed to load frame of walls\n");
}

void	load_animation(t_data *data)
{
	data->frame_collectable[0] = mlx_xpm_file_to_image(data->mlx,
			"textures/flower1.xpm", &(int){0}, &(int){0});
	if (!data->frame_collectable[0])
		ft_msg_destroy(data, "Failed to load frame 0 of collectable\n");
	data->frame_collectable[1] = mlx_xpm_file_to_image(data->mlx,
			"textures/flower2.xpm", &(int){0}, &(int){0});
	if (!data->frame_collectable[1])
		ft_msg_destroy(data, "Failed to load frame 1 of collectable\n");
	data->frame_enemy[0] = mlx_xpm_file_to_image(data->mlx,
			"textures/spider1.xpm", &(int){0}, &(int){0});
	if (!data->frame_enemy[0])
		ft_msg_destroy(data, "Failed to load frame 0 of enemy\n");
	data->frame_enemy[1] = mlx_xpm_file_to_image(data->mlx,
			"textures/spider2.xpm", &(int){0}, &(int){0});
	if (!data->frame_enemy[1])
		ft_msg_destroy(data, "Failed to load frame 1 of enemy\n");
	data->f_exit[0] = mlx_xpm_file_to_image(data->mlx,
			"textures/shroom-red.xpm", &(int){0}, &(int){0});
	if (!data->f_exit[0])
		ft_msg_destroy(data, "Failed to load fram 0 of exit\n");
	data->f_exit[1] = mlx_xpm_file_to_image(data->mlx,
			"textures/shroom-red2.xpm", &(int){0}, &(int){0});
	if (!data->f_exit[1])
		ft_msg_destroy(data, "Failed to load fram 1 of exit\n");
}

void	ft_load_player(t_data *data)
{
	data->f_player_r[0] = mlx_xpm_file_to_image(data->mlx,
			"textures/butterfly1_r.xpm", &(int){0}, &(int){0});
	if (!data->f_player_r[0])
		ft_msg_destroy(data, "Failed to load frame 0 of pleyer\n");
	data->f_player_r[1] = mlx_xpm_file_to_image(data->mlx,
			"textures/butterfly2_r.xpm", &(int){0}, &(int){0});
	if (!data->f_player_r[1])
		ft_msg_destroy(data, "Failed to load frame 0 of pleyer\n");
	data->f_player_l[0] = mlx_xpm_file_to_image(data->mlx,
			"textures/butterfly1_l.xpm", &(int){0}, &(int){0});
	if (!data->f_player_l[0])
		ft_msg_destroy(data, "Failed to load frame 0 of pleyer\n");
	data->f_player_l[1] = mlx_xpm_file_to_image(data->mlx,
			"textures/butterfly2_l.xpm", &(int){0}, &(int){0});
	if (!data->f_player_l[1])
		ft_msg_destroy(data, "Failed to load frame 0 of pleyer\n");
}
