#include "libft.h"
char	*ft_strdup(const char *str)
{
	char	*dst;
	int		len;

	len = ft_strlen(str);
	dst = (char *)malloc((len + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	ft_memcpy(dst, str, len);
	dst[len] = '\0';
	return (dst);
}
