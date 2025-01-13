#include "so_long.h"
#include "libft/libft.h"
#include "gnl/get_next_line.h"

void    check_walls(t_data *walls)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(j < walls->width)
    {
        if (walls->map[0][j] != '1' || walls->map[walls->height - 1][j] != '1')
            ft_error(walls, "bottom or up row has a non-wall(1)\n", 1);
        j++;
    }
    while(i < walls->height)
    {
        if(walls->map[i][0] != '1' || walls->map[i][walls->width - 1] != '1')
            ft_error(walls, "left or right column has a non-wall(1)\n", 1);
        i++;
    }
}

void    save_map(int fd, t_data *w)
{
    int     i;
    char    *line;

    w->map = NULL;
    line = get_next_line(fd);
    if(!line || line[0] == '\n')
        ft_error(w, "Nothing to read in the file!\n", 0);
    w->width = ft_strlen(line) - 1; //1 for new line
    w->map = ft_calloc(w->width, sizeof(char *));
    if(!w->map)
        exit(0);
    i = 0;
    while(line != NULL)
    {
        if(line[0] == '\n')
            ft_error(w, "Empty line in the map!\n", 1);
        w->height++;
        w->map[i] = ft_strdup(line);
        if(!w->map[i])
            (ft_free(w->map), exit(0));
        line = get_next_line(fd);
        i++;
    }
}

int p_position(t_data *w)
{
    int i;
    int j;

    i = 0;
    w->p_x = -1;
    w->p_y = -1;
    w->p = 0;
    while(w->map[i] != NULL)
    {
        j = 0;
        while(w->map[i][j] != '\0')
        {
            if(w->map[i][j] == 'P')
            {
                w->p_x = i;
                w->p_y = j;
                w->p++;
            }
            j++;
        }
        i++;
    }
    if(w->p_x == -1 || w->p_y == -1)
        return (1);
    return (0);
}
int	ft_iselement(char elem)
{
	if (elem != 'E' && elem != 'P' && elem != 'M' && elem != 'C' && elem != '0' && elem != '1')
		return (0);
	return (1);
}
int charcters(t_data *wl)
{
    int i;
    int j;

    i = 0;
    wl->c = 0;
    wl->e = 0;
    while(wl->map[i] != NULL)
    {
        j = 0;
        while(wl->map[i][j] != '\0' && wl->map[i][j] != '\n')
        {
            if(wl->map[i][j] == 'E')
                wl->e++;
            else if(wl->map[i][j] == 'C')
                wl->c++;
            else if(ft_iselement(wl->map[i][j]) == 0)
                return (1);
            j++;
        }
        i++;
    }
    if(wl->c == 0 || (wl->p > 1  || wl->p == 0) || (wl->e > 1 || wl->e == 0))
        return (1);
    return (0);
}

void    check_map(t_data *dt)
{
    int     fd;

    fd = open(dt->path, O_RDONLY);
    if(fd < 0)
        ft_error(dt, "can't open the file!\n", 0);
    save_map(fd, dt);
    close(fd);
    check_walls(dt);
    if(p_position(dt) == 1 || charcters(dt) == 1)
    {
        if (charcters(dt) == 1)
            printf("%s\n", dt->map[3]);
        ft_error(dt, "invalide rule of characters\n", 1);
    }
        
}

//______________________________________________________________________________________

// #include "libsolong.h"
// #include "git_next_line/get_next_line.h"
// #include "libft/libft.h"

// int check_walls(char **map, int w, int h)
// {
//     int i;
//     int j;

//     i = 0;
//     j = 0;
//     while(j < w)
//     {
//         if (map[0][j] != '1' || map[h - 1][j] != '1')
//             return (1); // Invalid if top or bottom w has a non-wall
//         j++;
//     }
//     while(i < h)
//     {
//         if(map[i][0] != '1' || map[i][w - 1] != '1')
//             return (1); // Invalid if left or right column has a non-wall
//         i++;
//     }
//     i = 0;
//     return (0);
// }

// char    **full_str(int fd, t_data *w)
// {
//     char    *str;
//     char    *tmp;
//     char    *line;

//     str = NULL;
//     line = get_next_line(fd);
//     if(!line)
//         return (NULL);
//     w->width = ft_strlen(line) - 1; //1 for new line
//     while(line != NULL)
//     {
//          w->height++;
//         tmp = str;
//         str = ft_strjoin(str, line); 
//         free(line);
//         if(line)
//             free(tmp);
//         if(!str)
//             return (NULL);
//         line = get_next_line(fd);
//     }
//     return (ft_split(str, '\n'));
// }

// int p_position(char **s, t_data *w)
// {
//     int i;
//     int j;

//     i = 0;
//     w->x = -1;
//     w->y = -1;
//     while(s[i] != NULL)
//     {
//         j = 0;
//         while(s[i][j] != '\0')
//         {
//             if(s[i][j] == 'P')
//             {
//                 w->x = i;
//                 w->y = j;
//                 return (0);
//             }
//             j++;
//         }
//         i++;
//     }
//     if(w->x == -1 || w->y == -1)
//         return (1);
//     return (0);
// }

// int charcters(char **s, t_data *wl)
// {
//     int i;
//     int j;

//     i = 0;
//     wl->p = 0;
//     wl->c = 0;
//     wl->e = 0;
//     while(s[i] != NULL)
//     {
//         j = 0;
//         while(s[i][j] != '\0')
//         {
//             if(s[i][j] == 'P')
//                 wl->p++;
//             if(s[i][j] == 'E')
//                 wl->e++;
//             if(s[i][j] == 'C')
//                 wl->c++;
//             j++;
//         }
//         i++;
//     }
//     if(wl->c == 0 || (wl->p > 1  || wl->p == 0) || (wl->e > 1 || wl->e == 0))
//         return (1);
//     return (0);
// }

// char    **check_map(char *path, t_data *data)
// {
//     int     fd;
//     char **arr;

//     fd = open(path, O_RDONLY);
//     if(fd < 0)
//         return (NULL);
//     arr = full_str(fd, data);
//     close(fd);
//     if(!arr)
//         return (NULL);
//     if(check_walls(arr, data->width, data->height) == 1 || p_position(arr, data) == 1 || charcters(arr, data))
//     {
//         ft_free(arr, data->height);// you should free all array
//         return (NULL);
//     }
//     return (arr);
// }


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