#include "minilibx-linux/mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*win;
	int		img_width;
	int		img_height;
	t_data	img;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 900, 900, "songul");
	img.img = mlx_xpm_file_to_image(mlx, "malika.xpm", &img_width, &img_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
				&img.endian);

	int i = 100;
	while(i <= 300)
	{
		int y = 100;
		while(y <= 300)
		{
			my_mlx_pixel_put(&img, i, y, 0x00FF0000);
			y++;
		}
		i++;
	}

	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_loop(mlx);	
}

