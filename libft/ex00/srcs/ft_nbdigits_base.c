#include "libft.h"

int		ft_nbdigits_base(unsigned int nb, int base)
{
	int				res;

	if (base < 2)
		return (-1);
	if (nb == 0)
		return (1);
	res = 0;
	while (nb)
	{
		res++;
		nb /= base;
	}
	return (res);
}

// returns the number of digits in an int;
