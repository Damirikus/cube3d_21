#include "libft.h"
void	*ft_memchr(const void *buf, int c, size_t count)
{
	const unsigned char	*ptr;

	ptr = buf;
	if (count == 0)
		return (NULL);
	while (count != 0)
	{
		if (*ptr == (unsigned char) c)
			return ((void *)ptr);
		ptr++;
		count--;
	}
	return (NULL);
}
