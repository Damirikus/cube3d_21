#include "libft.h"
static	int	ft_numsize(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		i++;
	}
	while (n != 0)
	{
		i++;
		n = (n / 10);
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*dest;
	int		len;
	long	lnumber;

	len = ft_numsize(n);
	lnumber = n;
	dest = (char *)malloc((len + 1) * sizeof (char));
	if (!dest)
		return (NULL);
	dest[len] = '\0';
	if (n < 0)
	{
		dest[0] = '-';
		lnumber = lnumber * (-1);
	}
	if (lnumber == 0)
		dest[0] = '0';
	while (lnumber != 0)
	{
		len--;
		dest[len] = (lnumber % 10) + '0';
		lnumber = (lnumber / 10);
	}
	return (dest);
}
