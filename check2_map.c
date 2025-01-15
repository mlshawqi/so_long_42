#include "so_long.h"

char    **copy_map(char **arr, int size)
{
    char **str;
    int i;

    str = ft_calloc(size + 1, sizeof(char *));
    if (!str)
        return (NULL);
    i = 0;
    while (i < size)
    {
        str[i] = strdup(arr[i]);
        if (!str[i])
        {
            ft_free(str);
            return (NULL);
        }
        i++;
    }
    str[i] = NULL;
    return (str);
}

void flood_fill(char **str, t_data *wl, int x, int y)
{
    if (x < 0 || y < 0 || y >= wl->width || x >= wl->height ||
        str[x][y] == '1' || str[x][y] == 'M' || str[x][y] == 'V')
        return;
    if (str[x][y] == 'C')
        wl->collectable++;
    else if (str[x][y] == 'E')
        wl->exit = 1;
    else if (str[x][y] == 'P')
        wl->player++;
    str[x][y] = 'V';
    flood_fill(str, wl, x + 1, y); // Down
    flood_fill(str, wl, x - 1, y); // Up
    flood_fill(str, wl, x, y + 1); // Right
    flood_fill(str, wl, x, y - 1); // Left
}

void    check2_map(t_data *data)
{
    char    **map_copy;

    map_copy = copy_map(data->map, data->height);
    if (map_copy == NULL)
        ft_error(data, "Fail to copy map!\n", 1);
    data->collectable = 0;
    data->exit = 0;
    data->player = 0;
    flood_fill(map_copy, data, data->p_x, data->p_y);
    if (data->collectable != data->c || data->exit != data->e || data->player != data->p)
        ft_error(data, "The map has isolated areas that are inaccessible.\n", 1);
    ft_free(map_copy);
}

void    check_path(t_data *g, int argc, char *argv[])
{
    int len;

    if(argc == 2)
    {
        len = ft_strlen(argv[1]);
        if (ft_strcmp(argv[1] + (len - 4), ".ber") != 0 || open(argv[1], O_RDONLY) < 0)
            ft_error(g, "wrong extension '_'\n", 0);
        g->path = ft_strdup(argv[1]);   
    }
    else
        ft_error(g, "Need argv[1]\n", 0);
}