#include "libft.h"
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t			i;
	size_t			j;
	unsigned char	*src;
	unsigned char	*dst;

	i = 0;
	src = (unsigned char *)haystack;
	dst = (unsigned char *)needle;
	if (!dst[i])
		return ((char *)&src[i]);
	while (i < len && src[i])
	{
		j = 0;
		while (((i + j) < len) && (src[i + j] == dst[j]))
		{
			if (!dst[j + 1])
				return ((char *)&src[i]);
			j++;
		}
		i++;
	}
	return (0);
}
