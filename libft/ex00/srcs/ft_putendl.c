#include "libft.h"

void	ft_putendl(char *s)
{
	if (!s)
		return ;
	while (*s)
		write (1, s++, 1);
	write (1, "\n", 1);
}
