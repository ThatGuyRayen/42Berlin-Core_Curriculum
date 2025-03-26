#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*result;

	result = (char *) malloc(size + 1);
	if (result == NULL)
		return (NULL);
	ft_bzero(result, sizeof(char) * (size + 1));
	return (result);
}
//create a new string which hold 'size' characters excluding NULL
