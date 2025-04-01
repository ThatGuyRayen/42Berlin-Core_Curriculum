#include "libft.h"

int		ft_nbdigits(int nb)
{
	int			result;
	unsigned	unsigned_nb;

	unsigned_nb = (nb < 0)? -nb : nb;
	result = 1;
	while (unsigned_nb >= 10)
	{
		result++;
		unsigned_nb /= 10;
	}
	return (result);
}
