#include "libft.h"

int	is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	while (s1[i] && is_set(s1[i], set))
		i++;
	while (j > i && is_set(s1[j - 1], set))
		j--;
	ptr = (char *) malloc(sizeof(char) * (j - i + 1));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, &s1[i], j - i + 1);
	return (ptr);
}
