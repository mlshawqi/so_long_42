#include "libsolong.h"

#define ESCAPE 65307
#define KEY_LEFT 65361
#define KEY_RIGHT 65363
#define KEY_UP 65362
#define KEY_DOWN 65364
#define KEYPress 2
#define KEYPRESSMask 1L<<0


int	ft_close(int keycode, mlx_data *vars)
{
	if (keycode == ESCAPE) // Escape key
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else if (keycode == KEY_LEFT)
		printf("Left key pressed\n");
	else if (keycode == KEY_UP) // Up arrow key
		printf("Up key pressed\n");
	else if (keycode == KEY_RIGHT) // Right arrow key
		printf("Right key pressed\n");
	else if (keycode == KEY_DOWN) // Down arrow key
		printf("Down key pressed\n");
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
