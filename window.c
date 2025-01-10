#include "libsolong.h"
#include "git_next_line/get_next_line.h"
#include "libft/libft.h"


//gcc -Lminilibx-linux -lmlx_Linux -lX11 -lXext

int ber_extension(char *str)
{
    int len;

    len = ft_strlen(str);
    if(ft_strcmp(str + (len - 4), ".ber") != 0)
        return (1);
    return (0);
}

int	main(int argc, char *argv[])
{
	mlx_data	data;
    w_data      d_wall;

    d_wall.collumns = 0;
    d_wall.rows = 0;
    if(argc == 2 && ber_extension(argv[1]) == 0)
    {
        
        d_wall.map = check_map(argv[1], &d_wall);
        if(d_wall.map == NULL)
        {
            printf("not valide %d  %d\n", d_wall.collumns, d_wall.rows);
            return (0);
        }
        
        data.mlx = mlx_init();
        if(data.mlx == NULL)
             return (0);
        data.win = mlx_new_window(data.mlx, d_wall.collumns * 50, d_wall.rows * 50, "so_long");
        if(data.win == NULL)
        {
            mlx_destroy_display(data.mlx); // Cleanup MLX connection
            free(data.mlx);
            return (0);
        }
        //put_images(&data, map);
       mlx_loop(data.mlx);

        // mlx_destroy_window(data.mlx, data.win);
        // mlx_destroy_display(data.mlx);
        // free(data.mlx);
    }
    else
        printf("didnt entre");
    return (0);
}
