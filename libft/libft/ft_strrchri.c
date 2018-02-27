#include "libft.h"

size_t	ft_strrchri(const char *s, int c)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = 0;
	while (s && s[i])
	{
		if (s[i] == c)
			res = i;
		i++;
	}
	return (res);
}
