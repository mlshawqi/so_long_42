#include "libsolong.h"
#include "git_next_line/get_next_line.h"
#include "libft/libft.h"

int check_walls(char **map, int row, int colm)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(j < colm)
    {
        if (map[0][j] != '1' || map[row - 1][j] != '1')
            return (1); // Invalid if top or bottom row has a non-wall
        j++;
    }
    while(i < row)
    {
        if(map[i][0] != '1' || map[i][colm - 1] != '1')
            return (1); // Invalid if left or right column has a non-wall
        i++;
    }
    i = 0;
    return (0);
}

void flood_fill(w_data *wl, int x, int y)
{
    if (x < 0 || y < 0 || x >= wl->rows || y >= wl->collumns || wl->map[x][y] == '1' || wl->map[x][y] == 'V') {
        return;
    }
    if (wl->map[x][y] == 'C')
        wl->collectable++;
    else if (wl->map[x][y] == 'E')
        wl->exit = 1;
    if (wl->map[x][y] == 'P')
        wl->player++;
    wl->map[x][y] = 'V';
    flood_fill(wl, x + 1, y); // Down
    flood_fill(wl, x - 1, y); // Up
    flood_fill(wl, x, y + 1); // Right
    flood_fill(wl, x, y - 1); // Left
}



char    **full_str(int fd, w_data *w)
{
    char    *str;
    char    *tmp;
    char    *line;

    str = NULL;
    line = get_next_line(fd);
    if(!line)
        return (NULL);
    w->rows = ft_strlen(line) - 1; //1 for new line
    while(line != NULL)
    {
        w->collumns++;
        tmp = str;
        str = ft_strjoin(str, line); 
        free(line);
        free(tmp);
        if(!str)
            return (NULL);
        line = get_next_line(fd);
    }
    return (ft_split(str, '\n'));
}

int p_position(char **s, int *x, int *y)
{
    int i;
    int j;

    i = 0;
    (*x) = -1;
    (*y) = -1;
    while(s[i] != NULL)
    {
        j = 0;
        while(s[i][j] != '\0')
        {
            if(s[i][j] == 'P')
            {
                (*x) = i;
                (*y) = j;
                return (0);
            }
            j++;
        }
        i++;
    }
    if((*x) == -1 || (*y) == -1)
        return (1);
    return (0);
}

int charcters(w_data *wl)
{
    int i;
    int j;

    i = 0;
    wl->p = 0;
    wl->c = 0;
    wl->e = 0;
    while(wl->map[i] != NULL)
    {
        j = 0;
        while(wl->map[i][j] != '\0')
        {
            if(wl->map[i][j] == 'P')
                wl->p++;
            if(wl->map[i][j] == 'E')
                wl->e++;
            if(wl->map[i][j] == 'C')
                wl->c++;
            j++;
        }
        i++;
    }
    if(wl->c == 0 || (wl->p > 1  || wl->p == 0) || (wl->e > 1 || wl->e == 0))
        return (1);
    return (0);
}

char    **check_map(char *path, w_data *data)
{
    int     fd;
    int x;
    int y;
    char **arr;

    fd = open(path, O_RDONLY);
    if(fd < 0)
        return (NULL);
    arr = full_str(fd, data);
    close(fd);
    if(!arr)
        return (NULL);
    if(check_walls(arr, data->rows, data->collumns) == 1 || p_position(arr, &x, &y) == 1 || charcters(data))
    {
        ft_free(arr, data->collumns);// you should free all array
        return (NULL);
    }
    flood_fill(data, x, y);
    if(data->collectable != data->c || data->exit != data->e || data->player != data->p)
    {
        printf("here");
        ft_free(arr, data->collumns);
        
    }
        
    return (arr);
}


// int check_pos(char *s, int widt)
// {
//     int i;
//     int line;

//     i = 0;
//     while(s[i] != '\0')
//     {
//         line = 0;
//         while(s[i] != '\n' && s[i] != '\0')
//         {
//             if((s[i] == 'P' || s[i] == 'E' || s[i] == 'C') && (s[i + 1] == '1' && s[i - 1] == '1') 
//                                             && (s[i - widt - 1] == '1' && s[i + widt + 1] == '1'))
//                 return (1);
//             line++;
//             i++;         
//         }
//         if(line != widt)
//             return (1);
//         i++;
//     }
//     return (0);
// }