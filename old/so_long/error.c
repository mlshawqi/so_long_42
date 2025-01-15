/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saait-si <saait-si@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:05:21 by saait-si          #+#    #+#             */
/*   Updated: 2024/04/30 15:05:32 by saait-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_dbl_free(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

int	exit_function(char *msg, t_point *app, int flag)
{
	if (flag == 1)
		write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	ft_dbl_free(app->dbl_ptr);
	exit(flag);
	return (0);
}

void	error(char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	exit(0);
}
