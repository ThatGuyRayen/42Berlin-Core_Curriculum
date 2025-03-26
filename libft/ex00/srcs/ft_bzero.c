#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	if (n == 0)
		return ;
	size_t	i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = 0x00;
		i++;
	}
}

