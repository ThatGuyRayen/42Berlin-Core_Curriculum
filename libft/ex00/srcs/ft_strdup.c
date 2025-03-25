#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		str++;
		count++;
	}
	return (count);
}

void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_strdup(char *src)
{
	char	*ptr;

	ptr = (char *)malloc ((ft_strlen(src) + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_strcpy(ptr, src);
	return (ptr);
}
/*
#include <stdio.h>
int	main(void)
{
	char	str1[] = "hello";
	char	*dest;
	dest = ft_strdup(str1);
	printf("%s", dest);
	free(dest);
	return (0);
}
*/
