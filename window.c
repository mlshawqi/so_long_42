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

void flood_fill(char **str, w_data *wl, int x, int y)
{
    if (x < 0 || y < 0 || x >= wl->rows || y >= wl->collumns || str[x][y] == '1' || str[x][y] == 'V') {
        return;
    }
    if (str[x][y] == 'C')
        wl->collectable++;
    else if (str[x][y] == 'E')
        wl->exit = 1;
    if (str[x][y] == 'P')
        wl->player++;
    str[x][y] = 'V';
    flood_fill(str, wl, x + 1, y); // Down
    flood_fill(str, wl, x - 1, y); // Up
    flood_fill(str, wl, x, y + 1); // Right
    flood_fill(str, wl, x, y - 1); // Left
}

int	main(int argc, char *argv[])
{
	mlx_data	data;
    w_data      d_wall;

    d_wall.collumns = 0;
    d_wall.rows = 0;
    d_wall.collectable = 0;
    d_wall.player = 0;
    d_wall.exit = 0;
    if(argc == 2 && ber_extension(argv[1]) == 0)
    {
        
        d_wall.map = check_map(argv[1], &d_wall);
        if(d_wall.map == NULL)
        {
            printf("not valide %d  %d\n", d_wall.collumns, d_wall.rows);
            return (0);
        }
        flood_fill(d_wall.map, &d_wall, d_wall.x, d_wall.y);
        if(d_wall.collectable != d_wall.c || d_wall.exit != d_wall.e || d_wall.player != d_wall.p)
        {
            ft_free(d_wall.map, d_wall.rows);
            printf("invaled map smarter\n wsl_coll%d\n coll%d wsl_e%d\n e%d wsl_p%d\n p%d", d_wall.collectable, d_wall.c, d_wall.exit, d_wall.e, d_wall.player, d_wall.p);
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
        put_images(&data, d_wall.map);
        // mlx_loop(data.mlx);

        // mlx_destroy_window(data.mlx, data.win);
        // mlx_destroy_display(data.mlx);
        // free(data.mlx);
    }
    else
        printf("didnt entre");
    return (0);
}


/*
flood fill almost done just need to pass copy of map
and put image also almost done just need to add animation or what it call
and movment huh'tbh i dont think you're gonna finish this in 2days malika, and with fasting huhhh'
*/