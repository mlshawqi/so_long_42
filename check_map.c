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

char    **full_str(int fd, w_data *w)
{
    char    *str;
    char    *tmp;
    char    *line;

    str = NULL;
    line = get_next_line(fd);
    if(!line)
        return (NULL);
    w->collumns = ft_strlen(line) - 1; //1 for new line
    while(line != NULL)
    {
         w->rows++;
        tmp = str;
        str = ft_strjoin(str, line); 
        free(line);
        if(line)
            free(tmp);
        if(!str)
            return (NULL);
        line = get_next_line(fd);
    }
    return (ft_split(str, '\n'));
}

int p_position(char **s, w_data *w)
{
    int i;
    int j;

    i = 0;
    w->x = -1;
    w->y = -1;
    while(s[i] != NULL)
    {
        j = 0;
        while(s[i][j] != '\0')
        {
            if(s[i][j] == 'P')
            {
                w->x = i;
                w->y = j;
                return (0);
            }
            j++;
        }
        i++;
    }
    if(w->x == -1 || w->y == -1)
        return (1);
    return (0);
}

int charcters(char **s, w_data *wl)
{
    int i;
    int j;

    i = 0;
    wl->p = 0;
    wl->c = 0;
    wl->e = 0;
    while(s[i] != NULL)
    {
        j = 0;
        while(s[i][j] != '\0')
        {
            if(s[i][j] == 'P')
                wl->p++;
            if(s[i][j] == 'E')
                wl->e++;
            if(s[i][j] == 'C')
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
    char **arr;

    fd = open(path, O_RDONLY);
    if(fd < 0)
        return (NULL);
    arr = full_str(fd, data);
    close(fd);
    if(!arr)
        return (NULL);
    if(check_walls(arr, data->rows, data->collumns) == 1 || p_position(arr, data) == 1 || charcters(arr, data))
    {
        ft_free(arr, data->collumns);// you should free all array
        return (NULL);
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