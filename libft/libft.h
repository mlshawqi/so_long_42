#ifndef LIBFT_H
# define LIBFT_H

# include <stdint.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

char	**ft_split(char const *s, char c);
int	ft_strlen(char *s);
int	ft_strcmp(char *s1, char *s2);
void	ft_free(char **str);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_itoa(int n);

#endif