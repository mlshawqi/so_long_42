/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaouk <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-15 22:19:32 by machaouk          #+#    #+#             */
/*   Updated: 2025-01-15 22:19:32 by machaouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_key(t_data *var, int x, int y)
{
	if (var->map[x][y] == '0')
	{
		var->map[x][y] = 'P';
		var->map[var->p_x][var->p_y] = '0';
	}
	else if (var->map[x][y] == 'E')
	{
		if (var->collecting == var->c)
			ft_msg_destroy(var, "Congrats you won 🎉🥳\n");
		else
			return ;
	}
	else if (var->map[x][y] == 'M')
		ft_msg_destroy(var, "You lost the game 🐸\n");
	else if (var->map[x][y] == 'C')
	{
		var->collecting++;
		var->map[x][y] = 'P';
		var->map[var->p_x][var->p_y] = '0';
	}
	else if (var->map[x][y] == '1')
		return ;
	var->p_x = x;
	var->p_y = y;
	var->movement++;
}

int	ft_close(int keycode, t_data *vars)
{
	if (keycode == ESCAPE)
		ft_msg_destroy(vars, "Exit the game.\n");
	else if (keycode == KEY_LEFT)
	{
		check_key(vars, vars->p_x, vars->p_y - 1);
		vars->butterfly_r = 1;
	}
	else if (keycode == KEY_UP)
		check_key(vars, vars->p_x - 1, vars->p_y);
	else if (keycode == KEY_RIGHT)
	{
		check_key(vars, vars->p_x, vars->p_y + 1);
		vars->butterfly_r = 0;
	}
	else if (keycode == KEY_DOWN)
		check_key(vars, vars->p_x + 1, vars->p_y);
	else
		return (0);
	ft_draw_map(vars);
	return (0);
}

int	handle_window_close(t_data *vars)
{
	ft_msg_destroy(vars, "Window closed.\n");
	return (0);
}
