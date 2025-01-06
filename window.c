/*#include "minilibx-linux/mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
*/
#include <mlx.h>
typedef struct s_mlx
{
	void	*mlx_connection;
	void	*mlx_window;
	int	color;
}	t_mlx;;

int ft(int keysym, t_mlx *t)
{
    printf("Pressed %d\n", keysym);
    //sleep to appreciate loop_hook stopping
    sleep(1);
    return 1;
}


int	main()
{
	t_mlx	data;
	int	size = 400;
	int	sizeh = 400;

	data.mlx_connection = mlx_init();
	if(data.mlx_connection == NULL)
		return (0);
	data.mlx_window = mlx_new_window(data.mlx_connection, size, sizeh, "my window");
	if(data.mlx_window == NULL)
	{
		mlx_destroy_display(data.mlx_connection); // Cleanup MLX connection
		free(data.mlx_connection);
		return (0);
	}
	data.color = 0xFA0000;

	mlx_key_hook(data.mlx_window, ft, &data);
	mlx_loop_hook(data.mlx_connection, change_color, &data);
	mlx_loop(data.mlx_connection);

	mlx_destroy_window(data.mlx_connection, data.mlx_window);
        mlx_destroy_display(data.mlx_connection);
	free(data.mlx_connection);
        return (0);
}
