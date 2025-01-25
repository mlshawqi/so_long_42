/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaouk <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-17 11:38:38 by machaouk          #+#    #+#             */
/*   Updated: 2025-01-17 11:38:38 by machaouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_strline(char *line)
{
	int	i;

	i = 0;
	while (line && line[i] != '\n' && line[i] != '\0')
		i++;
	return (i);
}

void	ft_save(t_data *d)
{
	int	i;

	if (d->width > 300)
		ft_msg_destroy(d, "Error\nMap width exceeds 300 characters.❌\n");
	i = 0;
	while (d->map[i] != NULL)
	{
		if (d->map[i][0] == '\n' || ft_strline(d->map[i]) != d->width)
			ft_msg_destroy(d, "Error\nEmpty line or Inconsistent widths.!❌\n");
		d->height++;
		if (d->height > 200)
			ft_msg_destroy(d, "Error\nMap height exceeds 200 characters.❌\n");
		i++;
	}
}

void	ft_free_line(t_data *d, int fd)
{
	if (!d->line)
		ft_msg_destroy(d, "Error\nEmpty line in the map.❌\n");
	if (d->line[0] == '\n')
	{
		while (d->line != NULL)
		{
			ft_free2(d->line);
			d->line = get_next_line(fd);
		}
		ft_msg_destroy(d, "Error\nEmpty line in the map.❌\n");
	}
}

void	save_map(int fd, t_data *w)
{
	int	i;

	i = 0;
	w->line = get_next_line(fd);
	ft_free_line(w, fd);
	w->width = ft_strlen(w->line) - 1;
	w->map = ft_calloc(201, sizeof(char *));
	if (!w->map)
		ft_msg_destroy(w, "Error\nFail to allocate for  map!❌\n");
	while (w->line != NULL)
	{
		if (i < 200)
		{
			w->map[i] = ft_strdup(w->line);
			if (!w->map[i])
				ft_msg_destroy(w, "Error\nfail to allocate map[i]❌\n");
			i++;
		}
		ft_free2(w->line);
		w->line = get_next_line(fd);
	}
	w->map[i] = NULL;
	ft_save(w);
}

char	**copy_map(char **arr, int size)
{
	char	**str;
	int		i;

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
