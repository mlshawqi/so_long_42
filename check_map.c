#include "libsolong.h"
#include "git_next_line/get_next_line.h"

int check_walls(char *str, int *w, int hght)
{
    int i;
    int len;
    int line;

    i = 0;
    line = 0;
    while(str[i] != '\0')
    {
        len = 0;
        line++;
        while(str[i] != '\n' && str[i] != '\0')
        {
            if(*w == 0 || len == 0 || str[i + 1] == '\n' || line == hght)
            {
                if(str[i] != '1')
                    return (1);
            }
            i++;
            len++;
        }
        if(*w == 0)
            *w += i;
        i++;
    }
    return (0);
}

int charcters(char *st)
{
    int i;
    int p;
    int c;
    int e;

    i = 0;
    p = 0;
    c = 0;
    e = 0;
    while(st[i] != '\0')
    {
        if(st[i] == 'P')
            p++;
        if(st[i] == 'E')
            e++;
        if(st[i] == 'C')
            c++;
        i++;
    }
    if(c == 0 || (p > 1  || p == 0) || (e > 1 || e == 0))
        return (1);
    return (0);
}
int check_pos(char *s, int widt)
{
    int i;
    int line;

    i = 0;
    while(s[i] != '\0')
    {
        line = 0;
        while(s[i] != '\n' && s[i] != '\0')
        {
            if((s[i] == 'P' || s[i] == 'E' || s[i] == 'C') && (s[i + 1] == '1' && s[i - 1] == '1') 
                                            && (s[i - widt - 1] == '1' && s[i + widt + 1] == '1'))
                return (1);
            line++;
            i++;         
        }
        if(line != widt)
            return (1);
        i++;
    }
    return (0);
}

char    *full_str(int fd, int *hg)
{
    char    *str;
    char    *tmp;
    char    *line;

    str = NULL;
    line = get_next_line(fd);
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
    return (str);
}
char    *check_map(char *map, int  *h, int *w)
{
    char    *str;
    int     fd;

    fd = open(map, O_RDONLY);
    if(fd < 0)
        return (NULL);
    str = full_str(fd, h);
    close(fd);
    if(!str)
        return (NULL);
    if(check_walls(str, w, *h) == 1 || check_pos(str, *w) == 1 || charcters(str) == 1)
    {
        free(str);
        str = NULL;
    }
    return (str);
}