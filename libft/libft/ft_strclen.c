#include "libft.h"

size_t	ft_strclen(char *str, int c)
{
	size_t	i;

	i = 0;
	while (*str)
	{
		if (*str == c)
			i++;
		str++;
	}
	return (i);
}
