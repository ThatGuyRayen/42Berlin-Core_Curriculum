#include "libft.h"

void	ft_putnbr(int n)
{
	char	num;

	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		write (1, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_putnbr (n / 10);
	num = nb % 10 + '0';
	write (1, &num, 1);
}
