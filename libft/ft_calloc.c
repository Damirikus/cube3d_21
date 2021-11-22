#include "libft.h"
void	*ft_calloc(size_t number, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(number * size);
	if (ptr == 0)
		return (0);
	ft_memset(ptr, 0, number * size);
	return (ptr);
}
