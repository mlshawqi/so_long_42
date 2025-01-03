#include "minilibx-linux/mlx.h"
#include <X11/keysym.h>
#include <stdlib.h>
#include <stdio.h>

#define MALLOC_ERROR	1
#define	SIDE_LEN		800

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}				t_img;

/*
 * This struct contains all the mlx stuff 
 * and the image where i will buffer my pixels
*/
typedef struct	s_var
{
	void	*mlx;
	void	*win;
	t_img	img;
}	t_var;

//Plot in a 2D image the pixel
void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	//🚨 Line len is in bytes. WIDTH 800 len_line ~3200 (can differ for alignment)
	offset = (img->line_len * y) + (x * (img->bits_per_pixel / 8));	

	*((unsigned int *)(offset + img->img_pixels_ptr)) = color;
}

/*
 * 🔥 my_pixel_put
*/
void	color_screen(t_var *data, int color)
{
	for (int y = 0; y < SIDE_LEN; ++y)	
	{
		for (int x = 0; x < SIDE_LEN; ++x)
		{
			/*
			 * This function is much faster than the library one🏻
			 * 	~Buffer in the image and push only when ready-> No flickering effect
			*/
			my_pixel_put(&data->img, x, y, color);
		}
	}
}

/*
 * This time i plug color in hexadecimal directly
 * easy vanilla
*/
int	f(int keysym, t_var *data)
{

	if (keysym == XK_r)
		color_screen(data, 0xff0000);
	else if (keysym == XK_g)
		color_screen(data, 0xff00);
	else if (keysym == XK_b)
		color_screen(data, 0xff);
	else if (keysym == XK_Escape)
		exit(1);
	// push the READY image to window
	// the last parameters are the offset image-window
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);

	return 0;
}

int	main()
{
	t_var	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, SIDE_LEN, SIDE_LEN, "My window");
	
	// Code to create an image and get the related DATA
	vars.img.img_ptr = mlx_new_image(vars.mlx, SIDE_LEN, SIDE_LEN);
	vars.img.img_pixels_ptr = mlx_get_data_addr(vars.img.img_ptr, &vars.img.bits_per_pixel, &vars.img.line_len, &vars.img.endian);


	printf("Line_len %d <-> SIDE_LEN %d\n""bpp %d\n""endian %d\n", vars.img.line_len, SIDE_LEN, vars.img.bits_per_pixel, vars.img.endian);

	mlx_key_hook(vars.win, f, &vars);
	mlx_loop(vars.mlx);
}
