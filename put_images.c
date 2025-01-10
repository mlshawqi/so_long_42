#include "libsolong.h"

void	put_images(mlx_data *d, char **s_map)
{
	int		img_width;
	int		img_height;
    int     i;
	//t_data	img;
    i = 0;
	d->background = mlx_xpm_file_to_image(d->mlx, "textures/back1.xpm", &img_width, &img_height);
	d->wall = mlx_xpm_file_to_image(d->mlx, "textures/rocket.xpm", &img_width, &img_height);
	d->r_exit[0] = mlx_xpm_file_to_image(d->mlx, "textures/burroww1.xpm", &img_width, &img_height);
    d->r_exit[1] = mlx_xpm_file_to_image(d->mlx, "textures/burrow2.xpm", &img_width, &img_height);
	d->player[0] = mlx_xpm_file_to_image(d->mlx, "textures/nrabbit1.xpm", &img_width, &img_height);
    d->player[1] = mlx_xpm_file_to_image(d->mlx, "textures/nrabbit2.xpm", &img_width, &img_height);
    d->player[2] = mlx_xpm_file_to_image(d->mlx, "textures/nrabbit3.xpm", &img_width, &img_height);
    d->player[3] = mlx_xpm_file_to_image(d->mlx, "textures/nrabbit4.xpm", &img_width, &img_height);
	d->collect[0] = mlx_xpm_file_to_image(d->mlx, "textures/carrot1.xpm", &img_width, &img_height);
    d->collect[1] = mlx_xpm_file_to_image(d->mlx, "textures/carrot2.xpm", &img_width, &img_height);
	d->enemy[0] = mlx_xpm_file_to_image(d->mlx, "textures/enemy1.xpm", &img_width, &img_height);
    d->enemy[1] = mlx_xpm_file_to_image(d->mlx, "textures/enemy2.xpm", &img_width, &img_height);

    int x;
    int y = 0;
    int j;
    while (s_map[i] != NULL)
    {
        x = 0;
        j = 0;
        while(s_map[i][j] != '\n' && s_map[i][j] != '\0')
        {
            if(s_map[i][j] == '1')
                mlx_put_image_to_window(d->mlx, d->win, d->wall, x, y);
            else if(s_map[i][j] == '0')
                mlx_put_image_to_window(d->mlx, d->win, d->background, x, y);
            else if(s_map[i][j] == 'P')
                mlx_put_image_to_window(d->mlx, d->win, d->player[0], x, y);
            else if(s_map[i][j] == 'C')
                mlx_put_image_to_window(d->mlx, d->win, d->collect[0], x, y);
            else if(s_map[i][j] == 'E')
                mlx_put_image_to_window(d->mlx, d->win, d->r_exit[0], x ,y);
            else if(s_map[i][j] == 'M')
                mlx_put_image_to_window(d->mlx, d->win, d->enemy[0], x, y);
            x += 50;  
            j++;       
        }
        i++;
        y += 50;
    }

	mlx_loop(d->mlx);	
}