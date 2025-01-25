/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaouk <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-16 19:27:06 by machaouk          #+#    #+#             */
/*   Updated: 2025/01/16 20:29:58 by machaouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char		*get_next_line(int fd);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strcpy(char *dest, char *src);
int			ft_str_len(char *s, int sing);
char		*ft_strdup(char *s);
char		*ft_strndup(char *s, size_t len);

#endif
