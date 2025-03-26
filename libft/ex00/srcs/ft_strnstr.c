#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const unsigned char	*str;
	const unsigned char	*tofind;
	size_t	i;
	size_t	j;

	str = (const unsigned char *)haystack;
	tofind = (const unsigned char *)needle;
	if (*tofind == '\0')
		return ((char *)str);
	i = 0;
	while (str[i] != '\0' && i < n)
	{
		j = 0;
		while (str[i + j] == tofind[j] && tofind[j] != '\0' && (i + j) < n)
			j++;
		if (tofind[j] == '\0')
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
