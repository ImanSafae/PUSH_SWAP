#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	unsigned char	to_find;
	unsigned char	*str;

	i = 0;
	to_find = (unsigned char)c;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == to_find)
			return (str + i);
		i++;
	}
	return (NULL);
}
