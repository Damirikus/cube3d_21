#include "libft.h"
int	ft_memcmp(const void *s1, const void *s2, size_t size)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (size > 0)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		size--;
		i++;
	}
	return (0);
}
