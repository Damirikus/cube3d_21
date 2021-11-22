#include "libft.h"
void	*ft_memcpy(void *dst, const void *src, size_t num)
{
	char		*edst;
	const char	*esrc;

	if (!num || dst == src)
		return (dst);
	esrc = src;
	edst = dst;
	while (num > 0)
	{
		*edst = *esrc;
		num--;
		esrc++;
		edst++;
	}
	return (dst);
}
