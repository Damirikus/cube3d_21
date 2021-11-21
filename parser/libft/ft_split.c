#include "libft.h"
static	int	ft_countword(const char *s, char c)
{
	int		i;
	int		word;

	i = 0;
	word = 0;
	while (*s)
	{
		if (word == 0 && *s != c)
		{
			word = 1;
			i++;
		}
		if (word == 1 && *s == c)
			word = 0;
		s++;
	}
	return (i);
}

static	int	ft_lenword(const char *s, char c)
{
	int	len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

static	void	*ft_freedest(char **dest, int n)
{
	while (n--)
		free (dest[n]);
	free (dest);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		words;
	char	**dest;

	if (!s)
		return (NULL);
	i = 0;
	words = ft_countword((char *)s, c);
	dest = (char **) malloc(words * sizeof (char *) + 1);
	if (!dest)
		return (NULL);
	while (words--)
	{
		while (*s != '\0' && *s == c)
			s++;
		dest[i] = ft_substr((char *)s, 0, ft_lenword((char *)s, c));
		if (!dest[i])
			return (ft_freedest(dest, i));
		s += ft_lenword((char *)s, c);
		i++;
	}
	dest[i] = NULL;
	return (dest);
}
