#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const unsigned char	*str;
	const unsigned char	*last;

	str = (const unsigned char *)s;
	last = NULL;
	while (*str)
	{
		if (*str == (unsigned char)c)
			last = str;
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return ((char *)last);
}
