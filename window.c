#include "libsolong.h"

int ft(int keysym, t_mlx *t)
{
    printf("Pressed %d\n", keysym);
    //sleep to appreciate loop_hook stopping
    sleep(1);
    return 1;
}

int chack_map(char *str, int *h, int *w)
{
    int i = 0;

    while(str[i])
    {
        if(*w == 0 && str[i] == '1')
        {
            *w++;
            i++;
        }
        else if(str[i] )
        else
            return (1);
    }
    return (0);
}

int	main()
{
	mlx_data	data;
    int         fd;
    char        *s;
    int         height = 0;
    int         width = 0;

	data.mlx = mlx_init();
    fd = open("maps/map.ber", O_RDONLY);
	s = get_next_line(fd);
    while(s != NULL)
    {
        if(check_map(s, &height, &width) == 1)
            return (0,printf("map not valide"));
        free(s);
        s = get_next_line(s);
    }

    if(data.mlx == NULL)
		return (0);
    

	data.win = mlx_new_window(data.mlx, size, sizeh, "my window");
	if(data.win == NULL)
	{
		mlx_destroy_display(data.mlx); // Cleanup MLX connection
		free(data.mlx);
		return (0);
	}
	data.color = 0xFA0000;

	mlx_key_hook(data.win, ft, &data);
	mlx_loop_hook(data.mlx, change_color, &data);
	mlx_loop(data.mlx);

	mlx_destroy_window(data.mlx, data.win);
        mlx_destroy_display(data.mlx);
	free(data.mlx);
        return (0);
}
