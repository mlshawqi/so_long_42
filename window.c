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

int     change_color(t_mlx *data)
{
    // Fill the window with the current color
    //mlx_clear_window(data->mlx_connection, data->mlx_window);
    mlx_string_put(data->mlx_connection, data->mlx_window, 150, 150, data->color, "Color Changing Window!");

    // Cycle through some basic colors: RED, GREEN, BLUE
/*    if (data->color == 0xFF0000)        // If it's red
        data->color = 0x00FF00;        // Change to green
    else if (data->color == 0x00FF00)   // If it's green
        data->color = 0x0000FF;        // Change to blue
    else
	data->color = 0xFF0000;        // Otherwise, go back to red
*/
	data->color = 0x00FA00;	    	
    return (0);
}

/*int     button_press(int button, int x, int y, t_mlx *daata)
{
    if (button == 1)
        printf("Left mouse button pressed at (%d, %d)!\n", x, y);
    else if (button == 3)
        printf("Right mouse button pressed at (%d, %d)!\n", x, y);

    return (0);
}

int	handle_input(int keysym, t_mlx *daata)
{
    //Check the #defines
    //find / -name keysym.h 2>/dev/null
    //find / -name keysymdef.h 2>/dev/null
    if (keysym == XK_Escape)
    {
        printf("The %d key (ESC) has been pressed\n\n", keysym);
        mlx_destroy_window(daata->mlx_connection, daata->mlx_window);
        mlx_destroy_display(daata->mlx_connection);
        free(daata->mlx_connection);
        exit(1);
    }
    printf("The %d key has been pressed\n\n", keysym);
    return (0);
}*/

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
