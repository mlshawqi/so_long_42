#include "minilibx-linux/mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

typedef struct	m_data {
	void	*mlx;
	void	*win;
	void	*background;
	void	*wall;
	void	*r_exit[2];
	void	*player[4];
	void	*collect[2];
	void	*enemy[2];
}				mlx_data;

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

char    **full_str(int fd, int *rows, int *columns)
{
    char    *str;
    char    *tmp;
    char    *line;

    str = NULL;
    line = get_next_line(fd);
    if(!line)
        return (NULL);
    (*wid) = ft_strlen(line);
    while(line != NULL)
    {
        (*hg)++;
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
char    *check_map(char *map, int  *columns, int *rows)
{
    char    **str;
    int     fd;

    fd = open(map, O_RDONLY);
    if(fd < 0)
        return (NULL);
    str = full_str(fd, columns, rows);
    close(fd);
    if(!str)
        return (NULL);
    if(check_walls(str, *rows, *columns) == 1)
    {
        free(str);
        str = NULL;
    }
    return (str);
}

int	main(int argc, char *argv[])
{
	mlx_data	data;
    char        *map;
    int         rows = 0;
    int         columns = 0;

    if(argc == 20)
    {
        
        map = check_map(argv[1], &columns, &rows);
        if(map == NULL)
        {
            printf("not valide %d  %d\n", columns, rows);
            return (0);
        }
        
        data.mlx = mlx_init();
        if(data.mlx == NULL)
             return (0);
        data.win = mlx_new_window(data.mlx, rows * 50, columns * 50, "so_long");
        if(data.win == NULL)
        {
            mlx_destroy_display(data.mlx); // Cleanup MLX connection
            free(data.mlx);
            return (0);
        }
       mlx_loop(data.mlx);

        // mlx_destroy_window(data.mlx, data.win);
        // mlx_destroy_display(data.mlx);
        // free(data.mlx);
    }
    else
        printf("didnt entre");
    return (0);
}