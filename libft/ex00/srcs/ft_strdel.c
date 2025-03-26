#include "libft.h"

void	ft_strdel(char **str)
{
	if (!str)
		return ;
	free(*str);
	*str = NULL;
}
