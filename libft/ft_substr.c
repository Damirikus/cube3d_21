#include "libft.h"
char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char			*dst;
	unsigned int	strlen;

	if (str == NULL)
		return (NULL);
	strlen = ft_strlen(str);
	if (start > strlen)
		return (ft_strdup(""));
	if (ft_strlen(str + start) < len)
		len = ft_strlen(str + start);
	dst = malloc((len + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	ft_memcpy(dst, &str[start], len + 1);
	dst[len] = '\0';
	return (dst);
}
