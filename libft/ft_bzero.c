/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaouk <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-16 19:32:45 by machaouk          #+#    #+#             */
/*   Updated: 2025-01-16 19:32:45 by machaouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*t;
	size_t	i;

	t = (char *)s;
	i = 0;
	while (i < n)
	{
		t[i] = 0;
		i++;
	}
}
