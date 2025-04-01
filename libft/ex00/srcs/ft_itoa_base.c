#include "libft.h"

static void	init_base(char *base)
{
	int		i;

	i = 0;
	while (++i < 10)
		base[i] = i;
	while (i < 16)
	{
		base[i] = i - 10 + 'A';
		i++;
	}
	base[16] = 0;
}

//Returns a string containing conversion of n in the given base
//ignores the sign of n

char		*ft_itoa_base(int n, int base)
{
	char			charbase[17];
	char			*res;
	unsigned int	unsigned_n;
	int				nbdigits;

	if (base < 2 || base > 16)
		return (NULL);
	init_base(charbase);
	unsigned_n = (n < 0) ? -n : n;
	nbdigits = ft_nbdigits_base(unsigned_n, base);
	if (!(res = ft_strnew(nbdigits)))
		return (NULL);
	while (--nbdigits)
	{
		res[nbdigits] = charbase[unsigned_n % base];
		unsigned_n /= base;
	}
	return (res);
}
