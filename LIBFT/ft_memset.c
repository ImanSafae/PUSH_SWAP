#include "libft.h"
#include <string.h>
#include <stdio.h>

void	*ft_memset(void *dest, int src, size_t n)
{
	size_t		i;
	unsigned char	str;
	unsigned char	*dst;

	i = 0;
	dst = (unsigned char *)dest;
	str = (unsigned char)src;
	while ((i < n))
	{
		dst[i] = str;
		i++;
	}
	return (dest);
}
