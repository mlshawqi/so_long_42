#include "minilibx-linux/mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/*typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;*/

/*void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}*/

int	main(void)
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*wall;
	void	*end;
	void	*player;
	void	*collect;
	void	*enemy;
	int		img_width;
	int		img_height;
	//t_data	img;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 675, 675, "songul");
	img = mlx_xpm_file_to_image(mlx, "textures/back1.xpm", &img_width, &img_height);
	wall = mlx_xpm_file_to_image(mlx, "textures/rocket.xpm", &img_width, &img_height);
	end = mlx_xpm_file_to_image(mlx, "textures/burrow1.xpm", &img_width, &img_height);
	player = mlx_xpm_file_to_image(mlx, "textures/nrabbit1.xpm", &img_width, &img_height);
	collect = mlx_xpm_file_to_image(mlx, "textures/carrot1.xpm", &img_width, &img_height);
	enemy = mlx_xpm_file_to_image(mlx, "textures/enemy1.xpm", &img_width, &img_height);
	/*img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
				&img.endian);
	*/
	int i = 0;
	while(i <= 675)
	{
		mlx_put_image_to_window(mlx, win, wall, i, 0);
		i += 45;
	}
	int y = 0;
	while(y <= 675)
	{
		mlx_put_image_to_window(mlx, win, wall, 0, y);
		y += 45;
		int imj = 45;
		while(imj <= (675 - 45))
		{
			mlx_put_image_to_window(mlx, win, img, imj, y);
			imj += 45;
		}
		mlx_put_image_to_window(mlx, win, wall, imj, y);
	}
	
	//mlx_put_image_to_window(mlx, win, wall, 0, 0);
	mlx_put_image_to_window(mlx, win, enemy, 300,250);
	mlx_put_image_to_window(mlx, win, collect, 400, 400);
	mlx_put_image_to_window(mlx, win, end, 50, 50);
	mlx_put_image_to_window(mlx, win, player, 150, 150);

	mlx_loop(mlx);	
}