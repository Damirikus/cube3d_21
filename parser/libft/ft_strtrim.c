#include "libft.h"
char	*ft_strtrim(char const *str, char const *set)
{
	size_t	i;
	size_t	len;
	char	*dst;

	if (!str)
		return (NULL);
	i = 0;
	len = ft_strlen(str);
	while (ft_strchr(set, str[i]))
	{
		if (str[i] == '\0')
		{
			dst = (char *) malloc(sizeof (char));
			dst[0] = '\0';
			return (dst);
		}
		i++;
	}
	while (ft_strchr(set, str[len - 1]))
	{
		len--;
	}
	dst = ft_substr(str, i, len - i);
	return (dst);
}
