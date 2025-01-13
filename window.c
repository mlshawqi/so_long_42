#include "libsolong.h"
#include "git_next_line/get_next_line.h"
#include "libft/libft.h"

// gcc -Lminilibx-linux -lmlx_Linux -lX11 -lXext


int ft_close(int keycode, mlx_data *vars)
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

int ber_extension(char *str)
{
    int len;

    len = ft_strlen(str);
    if (ft_strcmp(str + (len - 4), ".ber") != 0)
        return (1);
    return (0);
}

char **copy_map(char **arr, int size)
{
    char **str;
    int i;

    str = malloc(sizeof(char *) * (size + 1));
    if (!str)
        return (NULL);
    i = 0;
    while (i < size)
    {
        str[i] = strdup(arr[i]);
        if (!str[i])
        {
            ft_free(str, i);
            return (NULL);
        }
        i++;
    }
    str[i] = NULL;
    return (str);
}

void flood_fill(char **str, mlx_data *wl, int x, int y)
{
    if (x < 0 || y < 0 || y >= wl->width || x >= wl->height || str[x][y] == '1' || str[x][y] == 'M' || str[x][y] == 'V')
    {
        return;
    }
    if (str[x][y] == 'C')
        wl->collectable++;
    else if (str[x][y] == 'E')
        wl->exit = 1;
    else if (str[x][y] == 'P')
        wl->player++;
    else if (str[x][y] != '0')
    {
        ft_free(wl->map, wl->height);
        exit(0);
    }
    str[x][y] = 'V';
    flood_fill(str, wl, x + 1, y); // Down
    flood_fill(str, wl, x - 1, y); // Up
    flood_fill(str, wl, x, y + 1); // Right
    flood_fill(str, wl, x, y - 1); // Left
}

int main(int argc, char *argv[])
{
    mlx_data data;

    data.height = 0;
    data.width = 0;
    data.collectable = 0;
    data.player = 0;
    data.exit = 0;
    if (argc == 2 && ber_extension(argv[1]) == 0)
    {

        data.map = check_map(argv[1], &data);
        if (data.map == NULL)
        {
            printf("not valide %d  %d\n", data.height, data.width);
            return (0);
        }
        data.map_copy = copy_map(data.map, data.height);
        if (data.map_copy == NULL)
        {
            ft_free(data.map, data.height);
            return (0);
        }
        // printf("%s\n", data.map_copy[0]);
        // printf("%s %d", data.map[0], data.height);
        flood_fill(data.map_copy, &data, data.x, data.y);
        // printf("c%d c%d\ne%d e%d\np%dp%d\n", data.collectable, data.c, data.exit, data.e, data.player, data.p);
        if (data.collectable != data.c || data.exit != data.e || data.player != data.p)
        {
            ft_free(data.map, data.height);
            return (0);
        }
        data.mlx = mlx_init();
        if (data.mlx == NULL)
            return (0);
        data.win = mlx_new_window(data.mlx, data.width * 50, data.height * 50, "so_long");
        if (data.win == NULL)
        {
            mlx_destroy_display(data.mlx); // Cleanup MLX connection
            free(data.mlx);
            return (0);
        }
        //put_images(&data);
        // mlx_string_put(data.mlx, data.win, 100, 100, 0xFF0000, "hello 32");
        mlx_loop_hook(data.mlx, put_images, &data);
        //mlx_loop(data.mlx);

        mlx_destroy_window(data.mlx, data.win);
        mlx_destroy_display(data.mlx);
        free(data.mlx);
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