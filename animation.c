/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaouk <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-15 22:19:01 by machaouk          #+#    #+#             */
/*   Updated: 2025/01/18 12:17:58 by machaouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_images(t_data *d)
{
	int	i;
	int	y;
	int	x;
	int	j;

	i = 0;
	y = 0;
	while (d->map[i] != NULL)
	{
		x = 0;
		j = 0;
		while (d->map[i][j] != '\n' && d->map[i][j] != '\0')
		{
			if (d->map[i][j] == '1')
				mlx_put_image_to_window(d->mlx, d->win, d->i_wall, x, y);
			if (d->map[i][j] == '0')
				mlx_put_image_to_window(d->mlx, d->win, d->i_background, x, y);
			x += 50;
			j++;
		}
		i++;
		y += 50;
	}
}

void	put_animate_image(t_data *swan, char hint, int x, int y)
{
	if (hint == 'P')
	{
		if (swan->butterfly_r == 0)
			mlx_put_image_to_window(swan->mlx, swan->win,
				swan->f_player_r[swan->current_frame], x, y);
		else if (swan->butterfly_r == 1)
			mlx_put_image_to_window(swan->mlx, swan->win,
				swan->f_player_l[swan->current_frame], x, y);
	}
	else if (hint == 'C')
		mlx_put_image_to_window(swan->mlx, swan->win,
			swan->frame_collectable[swan->current_frame], x, y);
	else if (hint == 'M')
		mlx_put_image_to_window(swan->mlx, swan->win,
			swan->frame_enemy[swan->current_frame], x, y);
	else if (hint == 'E')
		mlx_put_image_to_window(swan->mlx, swan->win,
			swan->f_exit[swan->current_frame], x, y);
}

int	animate(t_data *anim)
{
	long	counter;
	int		i;
	int		j;

	i = 0;
	while (anim->map[i] != NULL)
	{
		j = 0;
		while (anim->map[i][j] != '\0' && anim->map[i][j] != '\n')
		{
			put_animate_image(anim, anim->map[i][j], j * 50, i * 50);
			j++;
		}
		i++;
	}
	anim->current_frame = (anim->current_frame + 1) % 2;
	counter = 0;
	while (counter < MAX)
		counter++;
	return (0);
}

void	ft_draw_map(t_data *game)
{
	char	*ptr;

	put_images(game);
	ptr = ft_itoa(game->movement);
	game->n_move = ft_strjoin("movement : ", ptr);
	free(ptr);
	mlx_string_put(game->mlx, game->win, 20, 20, 0xFF0000, game->n_move);
	free(game->n_move);
	mlx_loop_hook(game->mlx, animate, game);
}
