#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const unsigned char *str;

	str = (const unsigned char *)s;
	while (*str)
	{
		if (*str == (unsigned char)c)
			return ((char *)str);
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (NULL);
}
