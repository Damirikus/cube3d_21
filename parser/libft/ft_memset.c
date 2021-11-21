#include "libft.h"
void	*ft_memset(void *dest, int value, size_t num)
{
	unsigned char	*str;

	str = (unsigned char *)dest;
	while (num > 0)
	{
		*str = (unsigned char)value;
		str++;
		num--;
	}
	return (dest);
}
