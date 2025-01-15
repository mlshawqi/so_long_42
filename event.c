#include "so_long.h"

void	check_key(t_data *var, int x, int y)
{
	if(var->map[x][y] == '0')
	{
		var->map[x][y] = 'P';
		var->map[var->p_x][var->p_y] = '0';
	}
	else if(var->map[x][y] == 'E')
	{
		if(var->collecting == var->c)
			ft_msg_destroy(var, "You won the game\n");
		else
			return;
	}
	else if(var->map[x][y] == 'M')
		ft_msg_destroy(var, "You lost the game\n");
	else if(var->map[x][y] == 'C')
	{
		var->collecting++;
		var->map[x][y] = 'P';
		var->map[var->p_x][var->p_y] = '0';
	}
	else if(var->map[x][y] == '1')
		return ;
	var->p_x = x;
	var->p_y = y;
	var->movement++;
}

int	ft_close(int keycode, t_data *vars)
{
	if (keycode == ESCAPE)
		ft_destroy(vars);
	else if (keycode == KEY_LEFT)
		check_key(vars, vars->p_x , vars->p_y - 1);
	else if (keycode == KEY_UP)
		check_key(vars, vars->p_x - 1, vars->p_y);
	else if (keycode == KEY_RIGHT)
		check_key(vars, vars->p_x, vars->p_y + 1);
	else if (keycode == KEY_DOWN)
		check_key(vars, vars->p_x + 1 , vars->p_y);
	//mlx_clear_window(vars->mlx, vars->win);
	ft_draw_map(vars);
	return (0);
}

// int	main(void)
// {
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 300, 300, "Hello world!");
// 	mlx_hook(vars.win, KEYPress, KEYPRESSMask, ft_close, &vars);
// 	mlx_loop(vars.mlx);
// }

// #include <stdio.h>

// typedef struct	s_vars {
// 	void	*mlx;
// 	void	*win;
// }				t_vars;

// int	key_hook(int keycode, t_vars *vars)
// {
// 	printf("Hello %d \n", keycode);
// 	return (0);
// }

// int	main(void)
// {
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
// 	mlx_key_hook(vars.win, key_hook, &vars);
// 	mlx_loop(vars.mlx);
// }
