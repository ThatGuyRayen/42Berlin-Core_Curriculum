#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	length;
	size_t	i;

	if (!s)
		return (NULL);
	length = ft_strlen(s);
	if (start >= length)
		return (malloc(1));
	if (len > length - start)
		len = length - start;
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
