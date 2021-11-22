#include "libft.h"
void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t			en;
	unsigned char	*undest;
	unsigned char	*unsrc;

	en = (len - 1);
	undest = (unsigned char *) dest;
	unsrc = (unsigned char *) src;
	if (!dest && !src)
		return (NULL);
	if (src < dest)
	{
		while (len--)
		{
			undest[en] = unsrc[en];
			en--;
		}
	}
	if (dest < src)
	{
		while (len--)
			*undest++ = *unsrc++;
	}
	return (dest);
}
