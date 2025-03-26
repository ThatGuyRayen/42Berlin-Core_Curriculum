#include "libft.h"

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
#include <stdio.h>

int	main(void)
{
	char src[] = "But Not harder MOMMY";
	char dest[ ] = "Fuck me ";
	printf("%s", ft_strcat(dest, src));
	return (0);
}*/
